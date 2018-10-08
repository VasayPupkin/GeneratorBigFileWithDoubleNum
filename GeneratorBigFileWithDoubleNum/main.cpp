#include <iostream>
#include <ctime>

#include "FileSystem.h"
#include "DoubleNumberGenerator.h"

using namespace std;

std::string unsortedFile = "unsorted";
std::string sortedFile = "sorted";

int main()
{
    ulong timeStart = time(NULL);
    if(FileSystem::createFile(unsortedFile)){
        double tmp;
        while (FileSystem::getFileSize(unsortedFile) <= GBYTE) {
            tmp = DoubleNumberGenerator::generateDoubleNumber();
            FileSystem::writeToFile(unsortedFile, std::to_string(tmp));
        }
    }
    ulong timeStop = time(NULL);
    FileSystem::writeToFile(unsortedFile, std::to_string(timeStop - timeStart));
    cout << "Hello World!" << endl;
    return 0;
}
