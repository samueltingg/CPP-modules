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

void printPairedVector(std::vector< std::pair<int, int> >& vec)
{
	std::vector< std::pair<int, int> >::const_iterator it = vec.begin();
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

std::vector< std::pair<int, int> > createPairedSequence(std::vector<int>& sequence)
{
	std::vector< std::pair<int, int> > pairedSeq;
	
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

void sortPairs(std::vector< std::pair<int, int> >& pairedSeq)
{
	std::vector< std::pair<int, int> >::iterator it = pairedSeq.begin();

	for (; it != pairedSeq.end(); ++it) {
		if (it->first > it->second)
			continue;
		int temp = it->first;
		it->first = it->second;
		it->second = temp;
	}
}

// updates vector with sorted sequence, for a range of numbers: left->right
void merge(std::vector< std::pair<int, int> >& pairedSeq, int left, int mid, int right)
{
	int leftSize = mid - left + 1;   // size of left half
    int rightSize = right - mid;      // size of right half

    // Temporary arrays
	std::vector< std::pair<int, int> > L(leftSize);
	std::vector< std::pair<int, int> > R(rightSize);

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
void mergeSort(std::vector< std::pair<int, int> >& pairedSeq, int left, int right)
{
	// Base Condition: if one num left
	if (left >= right) // why > ?
		return ;
	
	int mid = (left + right) / 2;
	mergeSort(pairedSeq, left, mid);
	mergeSort(pairedSeq, mid + 1, right);
	merge(pairedSeq, left, mid, right);
}

void transferLargerNumToFinalVector(std::vector< std::pair<int, int> >& pairedSeq, std::vector<int>& final)
{
	std::vector< std::pair<int, int> >::const_iterator it = pairedSeq.begin();
	for (; it != pairedSeq.end(); ++it) {
		final.push_back(it->first);
	}
}

std::vector<int> PmergeMe::sortSequence()
{
	std::vector< std::pair<int, int> > pairedSeq = createPairedSequence(_sequence);
	
	sortPairs(pairedSeq);
	printPairedVector(pairedSeq);
	mergeSort(pairedSeq, 0, pairedSeq.size() - 1);
	std::cout << "\n===After Merge Sort ===\n";
	printPairedVector(pairedSeq);
	
	std::vector<int> final;
	final.push_back(pairedSeq[0].second);
	transferLargerNumToFinalVector(pairedSeq, final);
	pairedSeq.erase(pairedSeq.begin());
		
	printVector(final);
	printPairedVector(pairedSeq);

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

