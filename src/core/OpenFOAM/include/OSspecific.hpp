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

InNamespace
    Foam

Description
    Functions used by OpenFOAM that are specific to POSIX compliant
    operating systems and need to be replaced or emulated on other systems.

SourceFiles
    POSIX.C

\*---------------------------------------------------------------------------*/

#ifndef OSspecific_H
#define OSspecific_H

#include "OpenFOAM/primitives/strings/lists/fileNameList.hpp"

#include <sys/types.h>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

//- Return the PID of this process
pid_t pid();

//- Return the parent PID of this process
pid_t ppid();

//- Return the group PID of this process
pid_t pgid();

//- Return true if environment variable of given name is defined
bool env(const word&);

//- Return environment variable of given name
//  Return string() if the environment is undefined
string getEnv(const word&);

//- Set an environment variable
bool setEnv(const word& name, const std::string& value, const bool overwrite);

//- Return the system's host name, as per hostname(1)
//  Optionally with the full name (as per the '-f' option)
string hostName(const bool full=false);

//- Return the system's domain name, as per hostname(1) with the '-d' option
string domainName();

//- Return the user's login name
string userName();

//- Is user administrator
bool isAdministrator();

//- Return home directory path name for the current user
fileName home();

//- Return home directory path name for a particular user
fileName home(const string& userName);

//- Return current working directory path name
fileName cwd();

//- Change the current directory to the one given and return true,
//  else return false
bool chDir(const fileName& dir);

//- Make a directory and return an error if it could not be created
//  and does not already exist
bool mkDir(const fileName&, mode_t=0777);

//- Set the file mode
bool chMod(const fileName&, const mode_t);

//- Return the file mode
mode_t mode(const fileName&, const bool followLink = true);

//- Return the file type: DIRECTORY or FILE
fileName::Type type(const fileName&, const bool followLink = true);

//- Does the name exist (as DIRECTORY or FILE) in the file system?
//  Optionally enable/disable check for gzip file.
bool exists
(
    const fileName&,
    const bool checkGzip=true,
    const bool followLink = true
);

//- Does the name exist as a DIRECTORY in the file system?
bool isDir(const fileName&, const bool followLink = true);

//- Does the name exist as a FILE in the file system?
//  Optionally enable/disable check for gzip file.
bool isFile
(
    const fileName&,
    const bool checkGzip=true,
    const bool followLink = true
);

//- Return size of file
off_t fileSize(const fileName&, const bool followLink = true);

//- Return time of last file modification
time_t lastModified(const fileName&, const bool followLink = true);

//- Return time of last file modification
double highResLastModified(const fileName&, const bool followLink = true);

//- Read a directory and return the entries as a string list
fileNameList readDir
(
    const fileName&,
    const fileName::Type=fileName::FILE,
    const bool filtergz=true,
    const bool followLink = true
);

//- Copy, recursively if necessary, the source to the destination
bool cp(const fileName& src, const fileName& dst, const bool followLink = true);

//- Create a softlink. dst should not exist. Returns true if successful.
bool ln(const fileName& src, const fileName& dst);

//- Rename src to dst
bool mv
(
    const fileName& src,
    const fileName& dst,
    const bool followLink = false
);

//- Rename to a corresponding backup file
//  If the backup file already exists, attempt with "01" .. "99" suffix
bool mvBak(const fileName&, const std::string& ext = "bak");

//- Remove a file, returning true if successful otherwise false
bool rm(const fileName&);

//- Remove a directory and its contents
bool rmDir(const fileName&);

//- Sleep for the specified number of seconds
unsigned int sleep(const unsigned int);

//- Close file descriptor
void fdClose(const int);

//- Check if machine is up by pinging given port
bool ping(const string&, const label port, const label timeOut);

//- Check if machine is up by pinging port 22 (ssh) and 222 (rsh)
bool ping(const string&, const label timeOut=10);

//- Execute the specified command
int system(const std::string& command);

//- Open a shared library. Return handle to library. Print error message
//  if library cannot be loaded (check = true)
void* dlOpen(const fileName& lib, const bool check = true);

//- Close a dlopened library using handle. Return true if successful
bool dlClose(void*);

//- Lookup a symbol in a dlopened library using handle to library
void* dlSym(void* handle, const std::string& symbol);

//- Report if symbol in a dlopened library could be found
bool dlSymFound(void* handle, const std::string& symbol);

//- Return all loaded libraries
fileNameList dlLoaded();

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
