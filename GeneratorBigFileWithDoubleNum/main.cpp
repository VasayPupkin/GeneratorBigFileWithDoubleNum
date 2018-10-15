#include <iostream>
#include <ctime>
#include <fstream>

#include "FileSystem.h"
#include "DoubleNumberGenerator.h"

using namespace std;

std::string unsortedFile = "unsorted";
std::string sortedFile = "sorted";

constexpr size_t strNumPerLoop = 1000;

int main()
{
    ulong timeStart = time(NULL);
    if(FileSystem::createFile(unsortedFile)){
        double tmp;
        std::string tmpString;
        size_t fileSize = GBYTE;
        size_t currentSize = 0;
        std::ofstream myfile;
        myfile.open (unsortedFile,std::ios_base::app);
        while (currentSize <= fileSize) {
            for(auto i = 0; i < strNumPerLoop; ++i){
                tmp = DoubleNumberGenerator::generateDoubleNumber();
                tmpString += std::to_string(tmp) + "\n";
                currentSize += tmpString.length();
                myfile << tmpString;
            }
        }
        myfile.close();
    }
    ulong timeStop = time(NULL);
    FileSystem::writeToFile(unsortedFile, std::to_string(timeStop - timeStart));

    std::cout<<"Hello world!!!"<<std::endl;
    return 0;
}
