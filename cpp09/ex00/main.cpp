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

void testGetConvertedValue()
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

int main(void)
{
	ocfTest();
	constructorErrorTest();
	testGetConvertedValue();


}
