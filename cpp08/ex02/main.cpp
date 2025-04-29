/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:05:03 by sting             #+#    #+#             */
/*   Updated: 2025/04/29 10:51:01 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

void printSection(const std::string &title) {
	std::cout << CYAN << BOLD << "\n=== " << title << " ===" << RESET
		<< std::endl;
}

void subjectPdfTests()
{
	printSection("Subject PDF Tests");
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// while (it != ite)
	// {
	// std::cout << *it << std::endl;
	// ++it;
	// }
	// std::stack<int> s(mstack);
}

void constructorTests()
{
	printSection("Testing MutantStack Constructors");
	MutantStack<int> mstack;

	for (int i = 0; i < 4; i++) {
		mstack.push(i);
	}

	std::cout << "Printing stack from the Top: \n";

	MutantStack<int> temp = mstack;
	while (!temp.empty()) {
		std::cout << temp.top() << '\n';
		temp.pop();
	}
}



int main(void)
{
	subjectPdfTests();
	constructorTests();
	// {
	// 	printSection("Test: 10,000 elements");
	// 	Span sp(10000);
	//
	// 	for (int i = 0; i < 10000; i++) {
	// 		sp.addNumber(i);
	// 	}
	//
	// 	std::cout << sp << '\n';
	// }
	
}
