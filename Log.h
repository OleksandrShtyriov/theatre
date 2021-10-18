#ifndef LOG_H_
#define LOG_H_

#include <iostream>
#include <fstream>

void writeToFile(const std::string filename, const std::string info);
std::string readFromFile(const std::string filename);

#endif

