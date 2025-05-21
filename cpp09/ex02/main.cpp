/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:05:03 by sting             #+#    #+#             */
/*   Updated: 2025/05/06 11:34:57 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits>
#include <cstdio>
#include <cctype>

void printSection(const std::string &title) {
	std::cout << CYAN << BOLD << "\n=== " << title << " ===" << RESET
		<< std::endl;
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Error: Expected more than 1 argument.\n";
		return (1);
	}
	
	std::vector<int> vector;
	try {
		argvToContainer(argv, vector);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}

	std::deque<int> deque;
	try {
		argvToContainer(argv, deque);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}

	PmergeMe pm;

	pm.sortSequence(vector);
	if (isSorted(vector))
		std::cout << "Sorted\n";
	else 
		std::cout << "Not Sorted\n";

	pm.sortSequence(deque);
	if (isSorted(deque))
		std::cout << "Sorted\n";
	else 
		std::cout << "Not Sorted\n";


}

