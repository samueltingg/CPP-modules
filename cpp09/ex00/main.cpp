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

void constructorTests()
{
	printSection("Testing MutantStack Constructors");

	BitcoinExchange bcExchange1("short.csv");
	std::cout << "bcExchange1: \n"<< bcExchange1 << '\n';

	BitcoinExchange bcExchange2(bcExchange1);
	std::cout << "bcExchange2: \n"<< bcExchange2 << '\n';
}

int main(void)
{
	constructorTests();
	/*{*/
	/*	try {*/
	/*		BitcoinExchange bc("data.csv");*/
	/*		std::cout << "printing database: \n";*/
	/*		std::cout << bc << '\n' << "testt\n";*/
	/*	}*/
	/*	catch (BitcoinExchange::ErrorOpeningFileException& e) {*/
	/*		std::cout << e.what() << '\n';*/
	/*	}*/
	/**/
	/**/
	/**/
	/*}		*/

}
