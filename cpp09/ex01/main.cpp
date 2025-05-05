/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:05:03 by sting             #+#    #+#             */
/*   Updated: 2025/05/05 11:20:50 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <limits>
#include <cstdio>
#include <cctype>

void printSection(const std::string &title) {
	std::cout << CYAN << BOLD << "\n=== " << title << " ===" << RESET
		<< std::endl;
}

void ocfTest()
{
	printSection("Testing RPN Constructors");

	RPN bcExchange1("short.csv");
	std::cout << "bcExchange1: \n"<< bcExchange1 << '\n';

	RPN bcExchange2(bcExchange1);
	std::cout << "bcExchange2: \n"<< bcExchange2 << '\n';
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: expected 1 argument only.\n";
		return (1);
	}

	

}
