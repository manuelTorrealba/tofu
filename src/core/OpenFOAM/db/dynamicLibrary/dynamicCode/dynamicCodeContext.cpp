/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2018 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "OpenFOAM/db/dynamicLibrary/dynamicCode/dynamicCodeContext.hpp"
#include "OpenFOAM/primitives/strings/stringOps/stringOps.hpp"
#include "OpenFOAM/db/IOstreams/hashes/OSHA1stream.hpp"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::dynamicCodeContext::dynamicCodeContext(const dictionary& dict)
:
    dict_(dict),
    code_(),
    localCode_(),
    include_(),
    options_(),
    libs_()
{
    // Expand dictionary entries

    // Note: removes any leading/trailing whitespace
    // - necessary for compilation options, convenient for includes
    // and body.

    const entry* codePtr = dict.lookupEntryPtr
    (
        "code",
        false,
        false
    );
    if (codePtr)
    {
        code_ = stringOps::trim(codePtr->stream());
        stringOps::inplaceExpand(code_, dict);
    }

    const entry* includePtr = dict.lookupEntryPtr
    (
        "codeInclude",
        false,
        false
    );
    if (includePtr)
    {
        include_ = stringOps::trim(includePtr->stream());
        stringOps::inplaceExpand(include_, dict);
    }

    const entry* optionsPtr = dict.lookupEntryPtr
    (
        "codeOptions",
        false,
        false
    );
    if (optionsPtr)
    {
        options_ = stringOps::trim(optionsPtr->stream());
        stringOps::inplaceExpand(options_, dict);
    }

    const entry* libsPtr = dict.lookupEntryPtr("codeLibs", false, false);
    if (libsPtr)
    {
        libs_ = stringOps::trim(libsPtr->stream());
        stringOps::inplaceExpand(libs_, dict);
    }

    const entry* localPtr = dict.lookupEntryPtr("localCode", false, false);
    if (localPtr)
    {
        localCode_ = stringOps::trim(localPtr->stream());
        stringOps::inplaceExpand(localCode_, dict);
    }

    // Calculate SHA1 digest from include, options, localCode, code
    OSHA1stream os;
    os  << include_ << options_ << libs_ << localCode_ << code_;
    sha1_ = os.digest();


    // Add line number after calculating sha1 since includes processorDDD
    // in path which differs between processors.

    if (codePtr)
    {
        addLineDirective(code_, codePtr->startLineNumber(), dict.name());
    }

    if (includePtr)
    {
        addLineDirective(include_, includePtr->startLineNumber(), dict.name());
    }

    // Do not add line directive to options_ (Make/options) and libs since
    // they are preprocessed as a single line at this point. Can be fixed.
    if (localPtr)
    {
        addLineDirective(localCode_, localPtr->startLineNumber(), dict.name());
    }
}


// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

void Foam::dynamicCodeContext::addLineDirective
(
    string& code,
    const label lineNum,
    const fileName& name
)
{
    code = "#line " + Foam::name(lineNum + 1) + " \"" + name + "\"\n" + code;
}


// ************************************************************************* //
