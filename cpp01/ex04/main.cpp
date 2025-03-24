/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:53:04 by sting             #+#    #+#             */
/*   Updated: 2025/03/21 18:14:31 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

/*
start -> 1st index of str to be replaced
end -> last index of str to be replaced
str -> str to replace with
*/
std::string replace_str(const std::string& oriStr, size_t start, size_t end, const std::string& str) {
	
    // Check if the indices are valid
    if (start > end || end >= oriStr.length()) {
		std::cout << "Invalid start or end indices." << std::endl;
		return (oriStr);
    }
	std::string	modifiedStr = oriStr.substr(0, start) + str + oriStr.substr(end + 1);
	return (modifiedStr);
}

/*
`npos` is constant that indicates `find()` not finding any matches (value = -1)
*/
void replaceAll(std::string& content, const std::string& s1, const std::string& s2) {
	
	size_t pos = 0;
	size_t s1_length = s1.length();

	if (s1_length == 0)
		return ;
	while ((pos = content.find(s1, pos)) != std::string::npos) {
		content = replace_str(content, pos, pos + s1.length() - 1, s2);
		pos += s2.length();
	}
}

int main(int argc, char **argv) {

	if (argc != 4) {
		std::cout << "Error: Program only takes in 3 arguments, <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string fileName = argv[1];
	std::string	s1 = argv[2];
	std::string s2 = argv[3];

	if (s1 == "") {
		std::cout << "Error: s1 cannot be an empty string" << std::endl;
		return (1);
	}
	if (s1 == s2) {
		std::cout << "Error: s1 cannot be same as s2" << std::endl;
		return (1);
	}

	std::ifstream	ifs(fileName.c_str()); // opens a input file stream to read from a specified file
	if (!ifs) {
		std::cerr << "Error opening file" << std::endl;
        return (1); 	
	}

	// extract string from file	
	std::string content;
	std::string	line;
	while (std::getline(ifs, line)) {
		content += line + "\n";	
	}
	ifs.close();

	if (content == "") {
		std::cout << "File is empty. Nothing to be replaced." << std::endl;
		return (0);
	}
	replaceAll(content, s1, s2);

	std::ofstream ofs((fileName + ".replace").c_str());
	ofs << content;
}
