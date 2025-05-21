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
	
	// try {
	// 	PmergeMe merge(argv);
	// 	// printSection("Original Sequence");
	// 	// std::cout << GREEN << "\nBefore: "<< RESET;
	// 	// merge.printOriSequence();
	// 	std::vector<int> sorted = merge.sortSequence();
	//
	// 	if (isSorted(sorted))
	//   		std::cout << "Sorted\n";
	// 	else 
	// 		std::cout << "Not Sorted\n";
	//
	// 	// std::cout << RED << "\nAfter: "<< RESET;
	// 	// printVector(sorted);
	// 	// printSection("Sorted Sequence");
	// }
	// catch (std::exception& e) {
	// 	std::cerr << "Error: " << e.what() << '\n';
	// }

	
	std::vector<int> vector;
	argvToContainer(argv, vector);
	std::deque<int> deque;
	argvToContainer(argv, deque);

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

