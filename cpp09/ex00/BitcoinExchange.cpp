/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:59:31 by sting             #+#    #+#             */
/*   Updated: 2025/04/30 18:26:54 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"



BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange:: Constructor Called" << std::endl;
}

std::ifstream openInputFile(const std::string& fileName) {

    std::ifstream ifs(fileName.c_str());
    if (!ifs)
		throw BitcoinExchange::ErrorOpeningFileException();
	std::cout << fileName << '\n';
	return ifs;
}

// loop through each line in file, 
// transfer insert key values to map
void loadDatabaseFromFile(std::string fileName, std::map<std::string, int>& database)
{
	std::ifstream ifs;
	std::string	line;

	ifs = openInputFile(fileName);

	(void)database;

	// while (std::getline(ifs, line)) 
}

BitcoinExchange::BitcoinExchange(std::string fileName)
{
	std::cout << "BitcoinExchange:: String Constructor Called" << std::endl;
	
	loadDatabaseFromFile(fileName, _database);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	std::cout << "BitcoinExchange:: Copy Constructor Called" << std::endl;
	(void)other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	std::cout << "BitcoinExchange:: Copy Assignment Operator Called" << std::endl;
	
	if (this == &other)
		return *this;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Bureaucrat:: Destructor Called" << std::endl;
}


const char* BitcoinExchange::ErrorOpeningFileException::what() const throw() { 
	return "Error opening file.";
}


