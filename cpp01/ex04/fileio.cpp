
#include <iostream>
#include <fstream>
#include "fileio.hpp"
#include <cstdlib>

/*
.close() is not needed because: 

when a std::ifstream or std::ofstream object goes out of scope, its destructor is called, and the file is automatically closed

*/
std::string readFile(const std::string& fileName) {
    std::ifstream ifs(fileName.c_str());
    if (!ifs) {
        std::cerr << "Error opening file: " << fileName << std::endl;
		exit(1);
    }
	std::string content;
	std::string	line;
	while (std::getline(ifs, line)) {
		content += line + "\n";	
	}
    return content;
}

void writeFile(const std::string& fileName, const std::string& content) {
    std::ofstream ofs(fileName.c_str());
    if (!ofs) {
        std::cerr << "Error writing to file: " << fileName << std::endl;
		exit(1);
    }
    ofs << content;
}
