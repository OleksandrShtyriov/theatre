#include "Log.h"

void writeToFile(std::string filename, const std::string info)
{
    FILE* file = fopen(filename.c_str(), "w");
    fputs(info.c_str(), file);

    fclose(file);
}

std::string readFromFile(const std::string filename)
{
    std::ifstream fin(filename);
    std::string info;

    fin >> info;
    fin.close();

    return info;
}

