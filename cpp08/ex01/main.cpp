/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:05:03 by sting             #+#    #+#             */
/*   Updated: 2025/04/28 10:13:24 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define GREY "\033[90m"

void printSection(const std::string &title) {
	std::cout << CYAN << BOLD << "\n=== " << title << " ===" << RESET
		<< std::endl;
}

int main(void)
{
	{
		printSection("Testing Span Constructors");
		Span integers(4);
		integers.addNumber(1);	
		integers.addNumber(2);	
		integers.addNumber(3);	
		integers.addNumber(4);	


		std::cout << integers << '\n';

		Span integers2(integers);
		Span integers3;
		integers3 = integers;

		std::cout << integers2 << '\n';
		std::cout << integers3 << '\n';
	}

}
