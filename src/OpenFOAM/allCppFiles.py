import os
import string
from shutil import move

def buildPathFile(root, name):
    ss = os.path.join(root, name).replace("\\","/")
    return ss

def go():

    fileTree = os.walk("..", topdown=False)
    
    fileDictionary = {}
    for root, dirs, files in fileTree:
        for name in files:
            if ".hpp" in name:
                ss = buildPathFile(root, name)
                newKey = name.replace(".hpp","")
                fileDictionary[newKey] = ss[7:]
    
    scriptDir = os.path.dirname(os.path.abspath(__file__))
    fileTree = os.walk(".", topdown=False)
    with open("cppFiles.txt", "w") as cf:
        for root, dirs, files in fileTree:
            for name in files:
                if ".cpp" in name:
                    filePath = os.path.join(os.path.join(root, name))
                    cf.write(filePath+'\n')

go()