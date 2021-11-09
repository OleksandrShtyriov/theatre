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

void appendToFile(const std::string filename, const std::string info)
{
    FILE* file = fopen(filename.c_str(), "a");
    fputs(info.c_str(), file);

    fclose(file);
}

std::string readPerfFileWithout(const std::string perfFilename, const std::string perfName)
{
    std::string result;
    std::string temp;
    std::ifstream fin(perfFilename);

    for (std::string line; std::getline(fin, temp); )
    {
        if (temp == perfName)
        {
            continue;
        }

        result += temp + "\n";
    }

    return result;
}

std::string readActorFileWithout(const std::string actFilename, const std::string name, 
                                const std::string role, const std::string perf)
{
    std::string result;

    std::string tempName;
    std::string tempRole;
    std::string tempPerf;

    std::ifstream fin(actFilename);

    for (; std::getline(fin, tempName); )
    {
        std::getline(fin, tempRole);
        std::getline(fin, tempPerf);

        if ((name == tempName) && (role == tempRole) && (perf == tempPerf))
        {
            continue;
        }

        result += tempName + "\n" + tempRole + "\n" + tempPerf + "\n";
    }

    return result;
}

std::string readActorFileWithout(const std::string actFilename, const std::string perf)
{
    std::string result;

    std::string tempName;
    std::string tempRole;
    std::string tempPerf;

    std::ifstream fin(actFilename);

    for (; std::getline(fin, tempName); )
    {
        std::getline(fin, tempRole);
        std::getline(fin, tempPerf);

        if (perf == tempPerf)
        {
            continue;
        }

        result += tempName + "\n" + tempRole + "\n" + tempPerf + "\n";
    }

    return result;
}

