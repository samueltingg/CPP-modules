/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:05:03 by sting             #+#    #+#             */
/*   Updated: 2025/04/25 20:51:26 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <climits>
#include <cstdio>
#include <cctype>

void printSection(const std::string &title) {
	std::cout << CYAN << BOLD << "\n=== " << title << " ===" << RESET
		<< std::endl;
}

void ocfTest()
{
	printSection("Testing MutantStack Constructors");

	BitcoinExchange bcExchange1("short.csv");
	std::cout << "bcExchange1: \n"<< bcExchange1 << '\n';

	BitcoinExchange bcExchange2(bcExchange1);
	std::cout << "bcExchange2: \n"<< bcExchange2 << '\n';
}

void constructorErrorTest()
{
	printSection("constructorErrorTest");
	try {
		BitcoinExchange bc("nonExistentFile");
		std::cout << "printing database: \n";
		std::cout << bc << '\n' << "testt\n";
	}
	catch (BitcoinExchange::ErrorOpeningFileException& e) {
		std::cout << e.what() << '\n';
	}
}

void getConvertedValueTest()
{
	printSection("Test: getConvertedValue()");

	std::string date;
	double value = 1;
	double convertedValue;

	BitcoinExchange bcExchange("short.csv");

	std::cout << "\n==== Test Case: No Exact match ====\n";
	date = "2010-09-17"; value = 1;
	std::cout << "Date: " << date << ", Value: " << value << '\n';
	convertedValue = bcExchange.getConvertedValue(date, value);
	std::cout << "Converted Value: " << convertedValue << '\n';


	std::cout << "\n==== Test Case: Exact Match ====\n";
	date = "2010-09-19"; value = 1;
	std::cout << "Date: " << date << ", Value: " << value << '\n';
	convertedValue = bcExchange.getConvertedValue(date, value);
	std::cout << "Converted Value: " << convertedValue << '\n';
}

void trimSpacesBothEnds(std::string& str)
{
	size_t start = 0;
	size_t end = str.length() - 1;
	
	while (start < str.length() && std::isspace(str[start]))
		++start;
	while (end > start && std::isspace(str[end]))
		--end;
	
	str = str.substr(start, end - start + 1);
}

void loadDatabseFromInputFile(std::string fileName, std::multimap<std::string, std::string>& database)
{
	size_t pipeIndex;
	std::string	line;
	std::string value;
	std::string date;

	std::ifstream ifs(fileName.c_str());
	if (!ifs)
		throw BitcoinExchange::ErrorOpeningFileException();

	std::getline(ifs, line); // skip first line: "data,value"
	while (std::getline(ifs, line)) {
		pipeIndex = line.find("|");
		// parse 'date'
		date = line.substr(0, pipeIndex);
		trimSpacesBothEnds(date);

		// parse 'value'
		if (pipeIndex == std::string::npos)
			value = "";
		else {
			value = line.substr(pipeIndex + 1);
			trimSpacesBothEnds(value);
		}
		
		database.insert(std::make_pair(date, value)); 
		// multimap::insert() expects a value_type, which is a std::pair.
	}
}

bool isValidDate(const std::string& date) {
	if (date.length() != 10)
		return false;

    int y, m, d;
    char c1, c2;

	// check format 'YYYY-MM-DD'
    if (std::sscanf(date.c_str(), "%4d%c%2d%c%2d", &y, &c1, &m, &c2, &d) != 5 || c1 != '-' || c2 != '-')
		return false;
	if (m < 1 || m > 12 || d < 0 || d > 31)
		return false;
	return true;
}

bool isValidValue(const std::string literal) 
{
	double num = strtod(literal.c_str(), NULL);
	if (num == -HUGE_VAL || num == HUGE_VAL)
		return false;
	else if (num < 0) {
		std::cout << "Error: not a positive number.\n";
		return false;
	}
	else if (num > std::numeric_limits<int>::max()) {
		std::cout << "Error: too large a number.\n";
		return false;
	}

	char	*endPtr = NULL;
	strtod(literal.c_str(), &endPtr);

	if (endPtr[0] != '\0') {
		std::cout << "Error: not a number.\n";
		return false;
	}
	return true;
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: expected one input file.\n";
		return (1);
	}

	std::multimap<std::string, std::string> database; 
	try {
		printSection("Input File:");
		loadDatabseFromInputFile(argv[1], database);
		std::map<std::string, std::string>::const_iterator it = database.begin();
		
		for (; it != database.end(); it++) {
			std::cout << it->first << " : " << it->second << '\n';
		}

	}
	catch (BitcoinExchange::ErrorOpeningFileException& e){
		std::cout << e.what() << '\n';
		return (1);
	}

	printSection("After Conversion: ");
	try {
		BitcoinExchange bcX("data.csv");
		std::map<std::string, std::string>::const_iterator it = database.begin();
		for (; it != database.end(); it++) {

			if (!isValidDate(it->first)) {
				std::cout << "Error: bad input. => " << it->first << '\n';
				continue;
			}
			if (!isValidValue(it->second)) 
				continue;
			
			double value = strtod(it->second.c_str(), NULL);
			std::cout << it->first << " => " << it->second << " = " << bcX.getConvertedValue(it->first, value) << '\n';
		}
	}
	catch (BitcoinExchange::ErrorOpeningFileException& e){
		std::cout << e.what() << '\n';
	}




	// ocfTest();
	// constructorErrorTest();
	// getConvertedValueTest();
}
