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

BitcoinExchange::BitcoinExchange() : _database()
{
	std::cout << GREY << "BitcoinExchange:: Constructor Called" << RESET << std::endl;
}

void loadDatabaseFromCsv(std::string fileName, std::map<std::string, double>& database)
{
	std::string	line;
	int commaIndex;
	double value;

	std::ifstream ifs(fileName.c_str());
	if (!ifs)
		throw BitcoinExchange::ErrorOpeningFileException();

	std::getline(ifs, line); // skip first line: "data,value"
	while (std::getline(ifs, line)) {
		commaIndex = line.find(",");
		value = strtod(line.substr(commaIndex + 1).c_str(), NULL);
		database[line.substr(0, commaIndex)] = value; 
	}
}

BitcoinExchange::BitcoinExchange(std::string fileName) :_database()
{
	std::cout << GREY << "BitcoinExchange:: String Constructor Called" << RESET << std::endl;
	loadDatabaseFromCsv(fileName, _database);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database)
{
	std::cout << GREY << "BitcoinExchange:: Copy Constructor Called" << RESET << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	std::cout << GREY << "BitcoinExchange:: Copy Assignment Operator Called" << RESET << std::endl;
	
	if (this == &other)
		return *this;
	_database = other._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << GREY << "BitcoinExchange:: Destructor Called" << RESET << std::endl;
}


double BitcoinExchange::getConvertedValue(const std::string& date, double value)
{
	BitcoinExchange::const_iterator it = _database.begin();
	double exchangeRate;

	for (; it != _database.end(); it++) {
		if (it->first == date)
			break;
		// find 1st element greater than 'date'
		if (it->first > date) {
			if (it != _database.begin())
				--it; // get lower closet date
			break;
		}
	}
	exchangeRate = it->second;
	// std::cout << "exchangeRate found: " << exchangeRate << '\n';
	return value * exchangeRate;
}

BitcoinExchange::iterator BitcoinExchange::begin() 
{ 
	return _database.begin(); 
}

BitcoinExchange::iterator BitcoinExchange::end() 
{ 
	return _database.end(); 
}

const char* BitcoinExchange::ErrorOpeningFileException::what() const throw() { 
	return "Error opening file.";
}

std::ostream& operator<<(std::ostream& os, BitcoinExchange& bitcoinExchange)
{
	BitcoinExchange::const_iterator it = bitcoinExchange.begin();

	for (; it != bitcoinExchange.end(); it++) {
		os << it->first << " : " << it->second << '\n';
	}

	return os;
}
