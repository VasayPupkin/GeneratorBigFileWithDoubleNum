#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>

#define BYTE 1
#define kBYTE 1024*BYTE
#define MBYTE 1024*kBYTE
#define GBYTE 1024*MBYTE

class FileSystem
{
public:
    FileSystem() = delete;

    static bool checkFileExist(const std::string &filePath);
    static bool createFile(const std::string &filePath);
    static size_t getFileSize(const std::string &filePath);
    static void writeToFile(const std::string &filePath, const std::string &content);
};

#endif // FILESYSTEM_H
