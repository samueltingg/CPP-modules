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

// pairLevel = element size
// end: 'end of container' OR '1st num in leftover section'
void mergeInsertionSort(std::vector<int>& sequence, int pairLevel)
{
	static int recursionLevel = 1;
	std::cout << "==== Recursion Level: " << recursionLevel << " ====\n";
	recursionLevel++;

	int elementCount = sequence.size() / pairLevel;

	// Base Case
	if (elementCount <= 1)
		return ;

	bool isOdd = elementCount % 2 != 0;

	Iterator start = sequence.begin();
	Iterator last = sequence.begin() + (pairLevel * elementCount);
	Iterator end = isOdd ? (last - pairLevel) : last;

	// Sort Pairs
	int jump = pairLevel * 2;	

	for (; start != end; start += jump) {
		// swap a pair
		
		Iterator startBiggest = start + pairLevel - 1;
		Iterator nextBiggest = start + (pairLevel * 2) - 1;

		if (*startBiggest > *nextBiggest)
			swapWithinPair(start, pairLevel);

		printVector(sequence);
	}
	


	
	mergeInsertionSort(sequence, pairLevel * 2);
}
