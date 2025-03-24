#ifndef FILEIO_HPP
#define FILEIO_HPP

#include <string>

std::string readFile(const std::string& fileName);
void writeFile(const std::string& fileName, const std::string& content);

#endif 
