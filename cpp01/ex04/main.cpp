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

std::string replace_str(const std::string& oriStr, size_t start, size_t end, const std::string& str) {
	
    // Check if the indices are valid
    if (start > end || end >= oriStr.length()) {
        throw std::out_of_range("Invalid start or end indices.");
    }
	std::string	modifiedStr = oriStr.substr(0, start) + str + oriStr.substr(end + 1);
	return (modifiedStr);
}	

/*
`npos` is constant that indicates `find()` not finding any matches
*/
std::string	replaceAll(std::string& content, const std::string& s1, const std::string& s2) {
	
	size_t pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos) {
		content =  
	}	
}

int main(int argc, char **argv) {

	if (argc != 4) {
		std::cout << "Error: Program only takes in 3 arguments" << std::endl;
		return (1);
	}

	std::string fileName = argv[1];
	std::string	s1 = argv[2];
	std::string s2 = argv[3];


	std::ifstream	ifs(fileName); // opens a input file stream to read from a specified file
	if (!ifs) {
		std::cerr << "Error opening file" << std::endl;
        return (1); 	
	}
	
	std::string content;
	std::string	line;
	while (std::getline(ifs, line)) {
		content += line + "\n";	
	}


	ifs.close();


	std::ofstream ofs(fileName + ".replace");
	ofs << content;


}
