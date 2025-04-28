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
		Span sp(4);
		sp.addNumber(1);	
		sp.addNumber(2);	
		sp.addNumber(3);	
		sp.addNumber(4);	


		std::cout << sp << '\n';

		Span sp2(sp);
		Span sp3;
		sp3 = sp;

		std::cout << sp2 << '\n';
		std::cout << sp3 << '\n';
	}

	{
		printSection("Test: calling 'addNumber' when vector is full");
		Span sp(4);
		sp.addNumber(1);	
		sp.addNumber(2);	
		sp.addNumber(3);	
		sp.addNumber(4);	

		try {
			sp.addNumber(4);	
		}
		catch(std::exception &e) {
			std::cout << "Error: " << e.what() << '\n';
		}


	}

	{
		printSection("Test: 'longestSpan()' & 'shortestSpan'");
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	
	{
		printSection("Test: 'longestSpan()'");
		Span sp(1);
		sp.addNumber(6);
		try {
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << '\n';
		}

		Span sp2;
		try {
			std::cout << sp2.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << '\n';
		}

	}

}
