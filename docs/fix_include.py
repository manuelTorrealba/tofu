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
    for root, dirs, files in fileTree:
        for name in files:
            if ".cpp" in name or ".hpp" in name:
                filePath = os.path.join(scriptDir,os.path.join(root, name))
                filePathTmp = filePath + ".tmp"
                myFile = open(filePath,"r")
                myFileTmp = open(filePathTmp,"w")
                for line in myFile.readlines():
                    if "#include" in line and ".H" in line:
                        try:
                            sline = line.split("\"")[1].replace(".H","")
                            newLine = fileDictionary[sline]
                            line = "#include \"" + newLine + "\"\n"
                        except:
                            print(sline)
                            print(filePath + " failed")
                    myFileTmp.write(line)
                myFile.close()
                myFileTmp.close()
                os.remove(filePath)
                move(filePathTmp, filePath)

go()