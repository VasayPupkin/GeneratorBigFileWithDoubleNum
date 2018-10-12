#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <cstdio>

#include "FileSystem.h"


bool FileSystem::checkFileExist(const std::string &filePath)
{
    struct stat buffer;
    return (stat (filePath.c_str(), &buffer) == 0);
}

bool FileSystem::createFile(const std::string &filePath)
{
    if( !checkFileExist(filePath) ){
        try {
            std::ofstream file(filePath);
            return true;
        } catch (...) {
            std::cout << "File "<<filePath<<" not created!!!"<<std::endl;
            return false;
        }
    }
    return true;
}

size_t FileSystem::getFileSize(const std::string &filePath)
{
    std::streampos begin,end;
    std::ifstream myfile (filePath, std::ios_base::binary);
    begin = myfile.tellg();
    myfile.seekg (0, std::ios_base::end);
    end = myfile.tellg();
    myfile.close();
    return (end - begin);
}

void FileSystem::writeToFile(const std::string &filePath, const std::string &content)
{
    std::ofstream myfile;
    myfile.open (filePath,std::ios_base::app);
    myfile << content;
    myfile.close();
}
