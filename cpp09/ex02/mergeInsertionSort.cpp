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

// skips 0 -> 1, 1, 3, 5....
long generateJacobNum(long n)
{
	return static_cast<long>(round((pow(2, n + 1) + pow(-1, n)) / 3));
}

int searchInsertIndex(const std::vector<Iterator>& vec, int left, int right, int num)
{
    // base condition: if number not found
	if (left == right)
		return left;

    int mid = (left + right) / 2;

	if (num == *vec[mid]) // don't need if no duplicates
		return mid;
	else if (num < *vec[mid])
		return searchInsertIndex(vec, left, mid, num);
	else
		return searchInsertIndex(vec, mid + 1, right, num);
}


// std::upper_bound: returns an iterator point to 1st position this is greater than 'value'
void insertPendToMain(std::vector<Iterator>& pend, std::vector<Iterator>& main)
{
	std::vector<Iterator>::const_iterator pendIt = pend.begin();
	// TODO: find bound index(a) for each pend element(b)
	// std::vector<Iterator>::const_iterator boundIt =  
	
	for (; pendIt != pend.end(); ++pendIt) {
		std::vector<Iterator>::const_iterator idx = std::upper_bound(pend.begin(), pend.end(), **pendIt);
		main.insert(idx, *pendIt);
	}
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
	

	std::cout << "JACOB NUM: \n";
	for (int i = 0; i < 10; ++i) {
		std::cout << generateJacobNum(i) << '\n';
	}

	// TODO: Insert pend to main
	for (int i = 0; i < pend.size(); ++i) {
		int curJacob = generateJacobNum(i + 2);
		int prevJacob = generateJacobNum(i + 1);
		int batchSize = curJacob - prevJacob;

		for (int j = 0; j < batchSize; ++j) {
			
		}
	}

	// TODO: Insert remaining elements that cannot fit into batchSize
	
	
	// TODO: make a copy of values represented by iterators in 'main'
	

	// TODO: update 'ori container' with 'copy'

	

	std::cout << "\n==== Ori container ====\n";
	printVector(container);
	std::cout << "\n==== pend ====\n";
	printIteratorVector(pend);
	std::cout << "\n==== main ====\n";
	printIteratorVector(main);

}
