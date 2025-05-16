/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeInsertionSort.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:10:38 by sting             #+#    #+#             */
/*   Updated: 2025/05/14 18:23:55 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void swapWithinPair(Iterator start, int pairLevel)
{
	Iterator end = start + pairLevel;

	for (; start != end; start++) {
		std::iter_swap(start, start + pairLevel);
	}
}


void printIteratorVector(std::vector<Iterator>& vec)
{
	std::vector<Iterator>::const_iterator it = vec.begin();

	for (; it != vec.end(); ++it) {
		std::cout << *(*it) << " ";
	}
	std::cout << '\n';

}


int generateJacobNum(int n)
{
    double result = (pow(2, n + 1) + pow(-1, n)) / 3;
	return static_cast<int>(round(result));
}


// pairLevel = element size
// end: 'end of container' OR '1st num in leftover section'
void mergeInsertionSort(std::vector<int>& container, int pairLevel)
{
	static int recursionLevel = 1;
	std::cout << "==== Recursion Level: " << recursionLevel << " ====\n";
	recursionLevel++;

	int elementCount = container.size() / pairLevel;

	// Base Case
	if (elementCount <= 1)
		return ;

	bool isOdd = elementCount % 2 != 0;

	Iterator start = container.begin();
	Iterator last = container.begin() + (pairLevel * elementCount);
	Iterator end = isOdd ? (last - pairLevel) : last;

	// Sort Pairs
	int jump = pairLevel * 2;	

	for (; start != end; start += jump) {
		// swap a pair
		
		Iterator startBiggest = start + pairLevel - 1;
		Iterator nextBiggest = start + (pairLevel * 2) - 1;

		if (*startBiggest > *nextBiggest)
			swapWithinPair(start, pairLevel);

		printVector(container);
	}

	mergeInsertionSort(container, pairLevel * 2);

	std::cout << GREY << "\n==== Recursion Level ====\n" << RESET;
	recursionLevel++;
	std::cout << "Element count: " << elementCount << '\n';
	std::cout << "Pair Level: " << pairLevel << "\n\n";

	std::vector<Iterator> main;
	std::vector<Iterator> pend;

	// Transfer b1 & a1 to main
	main.push_back(container.begin() + pairLevel - 1);
	std::cout << "b1: " << *(container.begin() + pairLevel - 1) << '\n';
	main.push_back(container.begin() + (pairLevel * 2) - 1);
	std::cout << "a1: " << *(container.begin() + pairLevel * 2 - 1) << '\n';


	// transfer rest of a & b alternatively
	// i: element index
	for (int i = 3; i <= elementCount; i++) {
		if (i % 2 == 1) {
			pend.push_back(container.begin() + pairLevel * i - 1); // insert b
			std::cout << "b: " << *(container.begin() + pairLevel * i - 1) << '\n';
		}
		else {
			main.push_back(container.begin() + pairLevel * i - 1); // insert a
			std::cout << "a: " << *(container.begin() + pairLevel * i - 1) << '\n';
		}
	}

	// TODO: Insert pend to main
	
	
	
	// TODO: make a copy of values represented by iterators in 'main'
	

	// TODO: update 'ori container' with 'copy'

	

	std::cout << "\n==== Ori container ====\n";
	printVector(container);
	std::cout << "\n==== pend ====\n";
	printIteratorVector(pend);
	std::cout << "\n==== main ====\n";
	printIteratorVector(main);

}
