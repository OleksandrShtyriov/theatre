#ifndef LOG_H_
#define LOG_H_

#include <iostream>
#include <fstream>

void writeToFile(const std::string filename, const std::string info);
std::string readFromFile(const std::string filename);

void appendToFile(const std::string filename, const std::string info);

std::string readPerfFileWithout(const std::string perfFilename, const std::string perfName);
std::string readActorFileWithout(const std::string actFilename, const std::string name, 
                            const std::string role, const std::string perf);
std::string readActorFileWithout(const std::string actFilename, const std::string perf);

#endif

