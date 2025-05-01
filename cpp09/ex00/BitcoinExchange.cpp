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
	return ifs;
}

void loadDatabaseFromFile(std::string fileName, std::map<std::string, double>& database)
{
	std::ifstream ifs;
	std::string	line;
	int comma_index;
	double value;

	ifs = openInputFile(fileName);

	std::getline(ifs, line); // skip first line: "data,value"
	while (std::getline(ifs, line)) {
		comma_index = line.find(",");
		value = strtod(line.substr(comma_index + 1).c_str(), NULL);
		database[line.substr(0, comma_index)] = value; 
	}
}

BitcoinExchange::BitcoinExchange(std::string fileName) 
{
	std::cout << "BitcoinExchange:: String Constructor Called" << std::endl;
	loadDatabaseFromFile(fileName, _database);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database)
{
	std::cout << "BitcoinExchange:: Copy Constructor Called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	std::cout << "BitcoinExchange:: Copy Assignment Operator Called" << std::endl;
	
	if (this == &other)
		return *this;
	_database = other._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Bureaucrat:: Destructor Called" << std::endl;
}

BitcoinExchange::iterator BitcoinExchange::begin() 
{ 
	return _database.begin(); 
}

BitcoinExchange::iterator BitcoinExchange::end() 
{ 
	return _database.end(); 
}

BitcoinExchange::reverse_iterator BitcoinExchange::rbegin() 
{ 
	return _database.rbegin(); 
}

BitcoinExchange::reverse_iterator BitcoinExchange::rend() 
{ 
	return _database.rend(); 
}


const char* BitcoinExchange::ErrorOpeningFileException::what() const throw() { 
	return "Error opening file.";
}


std::ostream& operator<<(std::ostream& os, BitcoinExchange& bitcoinExchange)
{
	std::map<std::string, double>::const_iterator it = bitcoinExchange.begin();

	for (; it != bitcoinExchange.end(); it++) {
		os << it->first << " : " << it->second << '\n';
	}

	return os;
}
