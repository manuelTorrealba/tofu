import os
import string
from shutil import move

def buildPathFile(root, name):
    ss = os.path.join(root, name).replace("\\","/")
    return ss

def go():

    scriptDir = os.path.dirname(os.path.abspath(__file__))
    fileTree = os.walk(".", topdown=False)
    allPaths = []
    allNames = []
    with open("file.txt","w") as ff:
            for root, dirs, files in fileTree:
                ff.write(root.upper()+"\n")
                for name in files:
                    filePath = os.path.join(root, name)
                    ff.write(name.upper()+"\n")
                    ff.write(filePath.upper()+"\n")
                    allNames.append(name)
                    allPaths.append(root)

    with open("fileDuplicates.txt","w") as ff:
        for idx, anm in enumerate(allNames):
            cc = allNames.count(anm)
            if cc > 1 and ('.cpp' in anm or '.hpp' in anm):
                ff.write(allPaths[idx] + ' ; ' + anm + '\n')

 
go()