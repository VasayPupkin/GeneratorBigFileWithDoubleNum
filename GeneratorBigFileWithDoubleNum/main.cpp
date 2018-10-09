#include <iostream>
#include <ctime>

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
        size_t fileSize = GBYTE;
        while (FileSystem::getFileSize(unsortedFile) <= fileSize) {
            for(auto i = 0; i < strNumPerLoop; ++i){
                tmp = DoubleNumberGenerator::generateDoubleNumber();
                FileSystem::writeToFile(unsortedFile, std::to_string(tmp));
            }
        }
    }
    ulong timeStop = time(NULL);
    FileSystem::writeToFile(unsortedFile, std::to_string(timeStop - timeStart));
    cout << "Hello World!" << endl;
    return 0;
}
