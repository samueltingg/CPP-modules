/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:24:46 by sting             #+#    #+#             */
/*   Updated: 2025/05/06 11:32:30 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


// Constructor
PmergeMe::PmergeMe() : _sequence()
{
	std::cout << GREY << "PmergeMe:: Constructor Called" << RESET << std::endl;
}


int strToInt(const std::string& str)
{
	char *endPtr;
	long num = strtol(str.c_str(), &endPtr, 10);

	if (endPtr[0] != '\0')
		throw PmergeMe::InvalidArgumentException();
	if (num < 0 || num > INT_MAX || num == LONG_MAX)
		throw PmergeMe::NumberOutOfRangeException();
	return num;
}

// String Contructor
PmergeMe::PmergeMe(char **sequence) : _sequence()
{
	std::cout << GREY << "PmergeMe:: String Constructor Called" << RESET << std::endl;
	
	for (int i = 1; sequence[i]; ++i) {
		int num = strToInt(sequence[i]);	
		_sequence.push_back(num);
	}
}

// Copy Constructor
PmergeMe::PmergeMe(const PmergeMe& other) : _sequence(other._sequence)
{
	std::cout << GREY << "PmergeMe:: Copy Constructor Called" << RESET << std::endl;
}

// Copy Assignment Operator
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	std::cout << GREY << "PmergeMe:: Copy Assignment Operator Called" << RESET << std::endl;
	
	if (this == &other)
		return *this;
	_sequence = other._sequence;
	return *this;
}

// Destructor
PmergeMe::~PmergeMe()
{
	std::cout << GREY << "PmergeMe:: Destructor Called" << RESET << std::endl;
}

// =====================================================================================

void printPairedVector(PairedSeq& vec)
{
	PairedSeq::const_iterator it = vec.begin();
	for (; it != vec.end(); ++it) {
		std::cout << "("<< it->first << ", " << it->second << ")" << '\n';
	}

}

void printVector(std::vector<int>& vec)
{
	std::vector<int>::const_iterator it = vec.begin();

	for (; it != vec.end(); ++it) {
		std::cout << *it << '\n';
	}

}

PairedSeq createPairedSequence(std::vector<int>& sequence)
{
	PairedSeq pairedSeq;
	
	size_t size = sequence.size();
	for (size_t i = 0; i < size; ++i) {
		if (i % 2 != 0)
			continue;
		if (i == size - 1) // for ODD seq, extra num paired with '-1'
			pairedSeq.push_back(std::make_pair(sequence[i], -1));
		else 
			pairedSeq.push_back(std::make_pair(sequence[i], sequence[i+1]));
	}
	return pairedSeq;
}

void sortPairs(PairedSeq& pairedSeq)
{
	PairedSeq::iterator it = pairedSeq.begin();

	for (; it != pairedSeq.end(); ++it) {
		if (it->first > it->second)
			continue;
		int temp = it->first;
		it->first = it->second;
		it->second = temp;
	}
}

// updates vector with sorted sequence, for a range of numbers: left->right
void merge(PairedSeq& pairedSeq, int left, int mid, int right)
{
	int leftSize = mid - left + 1;   // size of left half
    int rightSize = right - mid;      // size of right half

    // Temporary arrays
	PairedSeq L(leftSize);
	PairedSeq R(rightSize);

    // Copy data to temporary arrays
    for (int i = 0; i < leftSize; i++)
        L[i] = pairedSeq[left + i];
    for (int j = 0; j < rightSize; j++)
        R[j] = pairedSeq[mid + 1 + j];

    // Merge the two pairedSeq back into pairedSeq[left..right]
    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize) {
		if (L[i].first <= R[j].first)
			pairedSeq[k++] = L[i++];
		else
			pairedSeq[k++] = R[j++];
    }

    // Copy any remaining elements
    while (i < leftSize)
        pairedSeq[k++] = L[i++];

    while (j < rightSize)
        pairedSeq[k++] = R[j++];
}

// sorts Paired Sequence
void mergeSort(PairedSeq& pairedSeq, int left, int right)
{
	// Base Condition: if one num left
	if (left >= right) // why > ?
		return ;
	
	int mid = (left + right) / 2;
	mergeSort(pairedSeq, left, mid);
	mergeSort(pairedSeq, mid + 1, right);
	merge(pairedSeq, left, mid, right);
}

void transferLargerNumToFinalVector(PairedSeq& pairedSeq, std::vector<int>& final)
{
	PairedSeq::const_iterator it = pairedSeq.begin();
	for (; it != pairedSeq.end(); ++it) {
		final.push_back(it->first);
	}
}

int binarySearch(const std::vector<int>& final, int left, int right, int num)
{
    // base condition: if number not found
	if (left == right)
		return left;

    int mid = (left + right) / 2;
	std::cout << "\n----------\n";
	std::cout << "left index: " << left << '\n';	
	std::cout << "mid index: " << mid << '\n';	
	std::cout << "right index: " << right << '\n';	

	// std::cout << "mid value: " << final[mid] << '\n';	
	if (num == final[mid]) {
		std::cout << "num == final[mid]\n";
		return mid;
	}
	else if (num < final[mid]) {
		if (right - left + 1 == 3)
			return left;
		std::cout << "num < final[mid]\n";
		return binarySearch(final, left, mid, num);
	}
	else {
		if (right - left + 1 == 3)
			return right;
		// if (right == 2) {
		// 	std::cout << "error\n";
		// 	return (-1);
		// }

		std::cout << "num > final[mid]\n";
		return binarySearch(final, mid + 1, right, num);
	}
}

std::vector<int> PmergeMe::sortSequence()
{
	PairedSeq pairedSeq = createPairedSequence(_sequence);
	std::vector<int> final;
	
	sortPairs(pairedSeq);
	printPairedVector(pairedSeq);
	mergeSort(pairedSeq, 0, pairedSeq.size() - 1);
	std::cout << "\n===After Merge Sort ===\n";
	printPairedVector(pairedSeq);

	if (pairedSeq[0].second != -1)
		final.push_back(pairedSeq[0].second); // insert first pair's smaller num pair
	transferLargerNumToFinalVector(pairedSeq, final);
	pairedSeq.erase(pairedSeq.begin());
		
	std::cout << "\n ===Final Vector with larger nums===\n";
	printVector(final);

	std::cout << "\n ===Paired vector after erasing first pair===\n";
	printPairedVector(pairedSeq);
	
	// insertSmallerElements
	// std::cout << "finalsize -1: " << final.size() - 1 << '\n';
	int index = binarySearch(final, 0, final.size() - 1, pairedSeq[1].second);
	std::cout << "index: " << index << '\n';

	return final;
}

void PmergeMe::printOriSequence()
{
	std::vector<int>::const_iterator it = _sequence.begin();

	for (; it != _sequence.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << '\n';

}

const char* PmergeMe::InvalidArgumentException::what() const throw() { 
	return "Invalid Argument.";
}

const char* PmergeMe::NumberOutOfRangeException::what() const throw() { 
	return "Number is out of range.";
}

