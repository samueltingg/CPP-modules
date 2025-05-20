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

void sortPairs(std::vector<int>& container, int pairLevel, int elementCount, bool isOdd)
{ 
	Iterator start = container.begin();
	Iterator last = container.begin() + (pairLevel * elementCount);
	Iterator end = isOdd ? (last - pairLevel) : last;

	int jump = pairLevel * 2;	

	for (; start != end; start += jump) {
		// swap a pair
		
		Iterator startBiggest = start + pairLevel - 1;
		Iterator nextBiggest = start + (pairLevel * 2) - 1;

		if (*startBiggest > *nextBiggest)
			swapWithinPair(start, pairLevel);

		printVector(container);
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


void transferElementsToMainAndPend(std::vector<int>& container, std::vector<Iterator>& main, std::vector<Iterator>& pend, int pairLevel, int elementCount)
{
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

}

// skips 0 -> 1, 1, 3, 5....
long generateJacobNum(long n)
{
	return static_cast<long>(round((pow(2, n + 1) + pow(-1, n)) / 3));
}

template <typename T>
bool comp(const T& a, const T& b)
{
	return *a < *b;
}

// std::upper_bound: returns an iterator point to 1st position this is greater than 'value'
void insertPendToMain(std::vector<Iterator>& pend, std::vector<Iterator>& main)
{
	for (int n = 2; true; ++n) {
		int curJacob = generateJacobNum(n);
		int prevJacob = generateJacobNum(n - 1);
		size_t batchSize = curJacob - prevJacob; // J(n) - J(n-1)

		if (pend.size() < batchSize)
			break;

		
		int insertedNumCount = 0;

		std::cout << "\nInit 'boundIt'  & 'pendIt': \n";
		std::vector<Iterator>::iterator boundIt = main.begin() + curJacob + insertedNumCount;
		std::vector<Iterator>::iterator pendIt = pend.begin() + batchSize - 1;
		if (boundIt != main.end())
			std::cout << "boundIt: " << **boundIt << '\n';
		else 
			std::cout << "boundIt: 'end()'\n";
		if (boundIt != pend.end())
			std::cout << "pendIt: " << **pendIt << '\n';
		
		// Insert batch
		for (size_t i = 0; i < batchSize; ++i) {
			std::vector<Iterator>::iterator idx = std::upper_bound(main.begin(), boundIt, *pendIt, comp<Iterator>);
			main.insert(idx, *pendIt);
			pendIt = pend.erase(pendIt);
			--pendIt;
			if (pendIt == pend.end())
				std::cout << "pendIt == end\n";
			std::cout << "CHECK\n";

			// update boundIt using 'offset'
			int offset = (idx == boundIt) ? true : false;
			boundIt = main.begin() + curJacob  + insertedNumCount - offset;
		}
		insertedNumCount += batchSize;
	}
	// TODO: Insert remaining elements that cannot fit into batchSize
	

	std::cout << "pend.size(): " << pend.size() << '\n';
	for (ssize_t i = (pend.size() - 1); i >= 0; --i) {
		std::vector<Iterator>::iterator curr_pend = pend.begin() + i;

		std::vector<Iterator>::iterator idx = std::upper_bound(main.begin(), main.end(), *curr_pend, comp<Iterator>);
		main.insert(idx, *curr_pend);
	}

}

// pairLevel = element size
// end: 'end of container' OR '1st num in leftover section'
void mergeInsertionSort(std::vector<int>& container, int pairLevel)
{
	static int recursionLevel = 0;
	int elementCount = container.size() / pairLevel;

	// Base Case
	if (elementCount <= 1) {
		std::cout << RED << "\n========= Recursion Level: " << ++recursionLevel << " =========\n" << RESET;
		return ;
	}
	std::cout << CYAN << "\n========= Recursion Level: " << ++recursionLevel << " =========\n" << RESET;

	bool isOdd = elementCount % 2 != 0;

	sortPairs(container, pairLevel, elementCount, isOdd);
	mergeInsertionSort(container, pairLevel * 2);

	std::cout << CYAN << "\n========= Recursion Level: " << --recursionLevel << " =========\n" << RESET;
	std::cout << "Element count: " << elementCount << '\n';
	std::cout << "Pair Level: " << pairLevel << "\n\n";

	std::vector<Iterator> main;
	std::vector<Iterator> pend;

	transferElementsToMainAndPend(container, main, pend, pairLevel, elementCount);


	std::cout << GREY << "\n==== Insert pend to main ====\n" << RESET;
	insertPendToMain(pend, main);
	std::cout << "After Inserting: \n";
	
	
	// TODO: make a copy of values represented by iterators in 'main'
	

	// TODO: update 'ori container' with 'copy' (copy until 'copy.size()' only)

	

	std::cout << "\n==== Ori container ====\n";
	printVector(container);
	std::cout << "\n==== pend ====\n";
	printIteratorVector(pend);
	std::cout << "\n==== main ====\n";
	printIteratorVector(main);
	std::cout << "\n==== Ori container(updated) ====\n";
	printVector(container);


}
