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

	{
		printSection("Test: calling 'addNumber' when vector is full");
		Span integers(4);
		integers.addNumber(1);	
		integers.addNumber(2);	
		integers.addNumber(3);	
		integers.addNumber(4);	

		try {
			integers.addNumber(4);	
		}
		catch(std::exception &e) {
			std::cout << "Error: " << e.what() << '\n';
		}


	}

}
