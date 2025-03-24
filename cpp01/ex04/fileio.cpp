/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileio.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:54:53 by sting             #+#    #+#             */
/*   Updated: 2025/03/24 15:54:54 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
