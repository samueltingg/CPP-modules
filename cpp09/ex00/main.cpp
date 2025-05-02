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

void loadDatabseFromInputFile(std::string fileName, std::multimap<std::string, double>& database)
{
	std::string	line;
	int pipeIndex;
	double value;

	std::ifstream ifs(fileName.c_str());
	if (!ifs)
		throw BitcoinExchange::ErrorOpeningFileException();

	std::getline(ifs, line); // skip first line: "data,value"
	while (std::getline(ifs, line)) {
		pipeIndex = line.find("|");
		value = strtod(line.substr(pipeIndex + 1).c_str(), NULL);
		database.insert(std::make_pair(line.substr(0, pipeIndex), value)); 
		// multimap::insert() expects a value_type, which is a std::pair.
	}
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: expected one input file.\n";
		return (1);
	}

	std::multimap<std::string, double> database; 
	try {
		loadDatabseFromInputFile(argv[1], database);
		std::map<std::string, double>::const_iterator it = database.begin();

		for (; it != database.end(); it++) {
			std::cout << it->first << " : " << it->second << '\n';
		}

	}
	catch (BitcoinExchange::ErrorOpeningFileException& e){
		std::cout << e.what() << '\n';
		return (1);
	}



	// test
	// ocfTest();
	// constructorErrorTest();
	// getConvertedValueTest();
}
