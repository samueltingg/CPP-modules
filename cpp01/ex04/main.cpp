/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:53:04 by sting             #+#    #+#             */
/*   Updated: 2025/03/21 14:27:20 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Error: Program only takes in 3 arguments" << std::endl;
		return (1);
	}

	std::string fileName = argv[1];

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
