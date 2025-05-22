/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:23:27 by sting             #+#    #+#             */
/*   Updated: 2025/05/14 17:54:23 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include <string>
#include <iostream>
#include <iomanip>
#include <exception>
#include <cstdlib>
#include <cmath>
#include <limits.h> 
#include <utility>
#include <algorithm>
#include <sys/time.h>
#include <cstdio>
#include <cctype>
#include <unistd.h>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define GREY "\033[90m"

// Utils
int strToInt(const std::string& str);
long generateJacobNum(long n);
int F(int n);

class PmergeMe {
public:
	// Default Constructor
	PmergeMe();
	// Copy Constructor
	PmergeMe(const PmergeMe& other);
	// Copy Assignment Operator
	PmergeMe& operator=(const PmergeMe& other);
	// Destructor
	~PmergeMe();

	template <typename ContainerType>
	void sortSequence(ContainerType& container);

	static int comparisonsCount; 	
};


// Exceptions:
class InvalidArgumentException : public std::exception {
public: 
	// 'throw()' specifies that func won't throw any exceptions 
	const char* what() const throw();
};

class NumberOutOfRangeException : public std::exception {
public: 
	// 'throw()' specifies that func won't throw any exceptions 
	const char* what() const throw();
};

class HasDuplicatesException : public std::exception {
public: 
	// 'throw()' specifies that func won't throw any exceptions 
	const char* what() const throw();
};

template<typename InputIt>
InputIt next(InputIt it, typename std::iterator_traits<InputIt>::difference_type n = 1)
{
    std::advance(it, n);
    return it;
}

template <typename ContainerType>
void argvToContainer(char **argv, ContainerType& container)
{
	for (int i = 1; argv[i]; ++i) {
		int num = strToInt(argv[i]);	
		container.push_back(num);
	}
}

template <typename ContainerType>
bool checkDuplicates(const ContainerType& container)
{
    typename ContainerType::const_iterator it1, it2;
    for (it1 = container.begin(); it1 != container.end(); ++it1)
    {
        it2 = it1;
        ++it2;
        for (; it2 != container.end(); ++it2)
        {
            if (*it1 == *it2)
                throw HasDuplicatesException();
        }
    }
    return false;
}


template <typename ContainerType>
bool isSorted(const ContainerType& container) {
    if (container.empty() || container.size() == 1) 
		return true; 

    typename ContainerType::const_iterator it = container.begin();
    typename ContainerType::const_iterator next = it;
    ++next;

    while (next != container.end()) {
        if (*it > *next)
            return false;
        ++it;
        ++next;
    }
    return true;
}

template <typename ContainerType>
void printContainer(ContainerType& container)
{
	typename ContainerType::const_iterator it = container.begin();

	if (container.size() > 6) {
		for (int i = 0; it != container.end() && i < 6; ++it, ++i) {
			std::cout << *it << " ";
		}
		std::cout << "[...]\n";
		return;
	}

	for (; it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << '\n';
}

template <typename ItType>
void printIteratorVector(std::vector<ItType>& vec)
{
	typename std::vector<ItType>::const_iterator it = vec.begin();

	for (; it != vec.end(); ++it) {
		std::cout << *(*it) << " ";
	}
	std::cout << '\n';

}

template <typename ItType>
void swapWithinPair(ItType start, int pairLevel)
{
	ItType end = next(start, pairLevel);
for (; start != end; start++) {
		std::iter_swap(start, next(start, pairLevel));
	}
}

template <typename ItType>
bool comp(const ItType& a, const ItType& b)
{
	PmergeMe::comparisonsCount++;
	return *a < *b;
}

template <typename ContainerType>
void sortPairs(ContainerType& container, int pairLevel, int elementCount, bool isOdd)
{ 
	typedef typename ContainerType::iterator Iterator;
	Iterator start = container.begin();
	Iterator last = next(container.begin(), pairLevel * elementCount);
	Iterator end = isOdd ? next(last, -pairLevel) : last;

	int jump = pairLevel * 2;	

	for (; start != end; std::advance(start, jump)) {
		// swap a pair
		
		Iterator startBiggest = next(start, pairLevel - 1);
		Iterator nextBiggest = next(start, (pairLevel * 2) - 1);

		// if (*startBiggest > *nextBiggest)
		if (comp(nextBiggest, startBiggest))
			swapWithinPair(start, pairLevel);

		// printContainer(container);
	}
}

template <typename ContainerType>
void transferElementsToMainAndPend(ContainerType& container, 
								   std::vector<typename ContainerType::iterator>& main, 
								   std::vector<typename ContainerType::iterator>& pend, 
								   int pairLevel, int elementCount)
{
	// Transfer b1 & a1 to main
	main.push_back(next(container.begin(), pairLevel - 1));
	// std::cout << "b1: " << *(container.begin() + pairLevel - 1) << '\n';
	main.push_back(next(container.begin(), (pairLevel * 2) - 1));
	// std::cout << "a1: " << *(container.begin() + pairLevel * 2 - 1) << '\n';


	// transfer rest of a & b alternatively
	// i: element index
	for (int i = 3; i <= elementCount; i++) {
		if (i % 2 == 1) {
			pend.push_back(next(container.begin(), pairLevel * i - 1)); // insert b
			// std::cout << "b: " << *(container.begin() + pairLevel * i - 1) << '\n';
		}
		else {
			main.push_back(next(container.begin(), pairLevel * i - 1)); // insert a
			// std::cout << "a: " << *(container.begin() + pairLevel * i - 1) << '\n';
		}
	}
}


// std::upper_bound: returns an iterator point to 1st position this is greater than 'value'
template <typename ItType>
void insertPendToMain(std::vector<ItType>& pend, std::vector<ItType>& main, bool isOdd)
{
	int insertedNumCount = 0;
	for (int n = 2; true; ++n) {
		int curJacob = generateJacobNum(n);
		int prevJacob = generateJacobNum(n - 1);
		size_t batchSize = curJacob - prevJacob; // J(n) - J(n-1)

		if (pend.size() < batchSize)
			break;
		// std::cout << "\nInit 'boundIt'  & 'pendIt': \n";
		typename std::vector<ItType>::iterator boundIt = main.begin() + curJacob + insertedNumCount;
		typename std::vector<ItType>::iterator pendIt = pend.begin() + batchSize - 1;
		// if (boundIt != main.end())
		// 	std::cout << "boundIt: " << **boundIt << '\n';
		// else 
		// 	std::cout << "boundIt: 'end()'\n";
		// if (boundIt != pend.end())
		// 	std::cout << "pendIt: " << **pendIt << '\n';
		
		// Insert batch
		for (size_t i = 0; i < batchSize; ++i) {
			typename std::vector<ItType>::iterator idx = std::upper_bound(main.begin(), boundIt, *pendIt, comp<ItType>);
			main.insert(idx, *pendIt);
			pendIt = pend.erase(pendIt);
			--pendIt;
			// if (pendIt == pend.end())
			// 	std::cout << "pendIt == end\n";

			// update boundIt using 'offset'
			int offset = (idx == boundIt) ? true : false;
			boundIt = main.begin() + curJacob  + insertedNumCount - offset;
		}
		insertedNumCount += batchSize;
	}
	// Insert remaining elements that cannot fit into batchSize
	for (ssize_t i = (pend.size() - 1); i >= 0; --i) {
		typename std::vector<ItType>::iterator curr_pend = pend.begin() + i;
		typename std::vector<ItType>::iterator curr_bound = main.begin() + (main.size() - pend.size() + i + isOdd);

		typename std::vector<ItType>::iterator idx = std::upper_bound(main.begin(), curr_bound, *curr_pend, comp<ItType>);
		main.insert(idx, *curr_pend);
	}

}

// pairLevel = element size
// end: 'end of container' OR '1st num in leftover section'
template <typename ContainerType>
void mergeInsertionSort(ContainerType& container, int pairLevel)
{
	typedef typename ContainerType::iterator Iterator;

	// static int recursionLevel = 0;
	int elementCount = container.size() / pairLevel;

	// Base Case
	if (elementCount <= 1) {
		// std::cout << RED << "\n========= Recursion Level: " << ++recursionLevel << " =========\n" << RESET;
		return ;
	}
	// std::cout << CYAN << "\n========= Recursion Level: " << ++recursionLevel << " =========\n" << RESET;

	bool isOdd = elementCount % 2 != 0;

	sortPairs(container, pairLevel, elementCount, isOdd);
	mergeInsertionSort(container, pairLevel * 2);

	// std::cout << CYAN << "\n========= Recursion Level: " << --recursionLevel << " =========\n" << RESET;
	// std::cout << "Element count: " << elementCount << '\n';
	// std::cout << "Pair Level: " << pairLevel << "\n\n";

	std::vector<Iterator> main;
	std::vector<Iterator> pend;

	transferElementsToMainAndPend(container, main, pend, pairLevel, elementCount);


	// std::cout << GREY << "\n==== Insert pend to main ====\n" << RESET;
	// std::cout << BOLD << "Before Insertion: \n" << RESET;
	// std::cout << "\n==== Ori container ====\n";
	// printContainer(container);
	// std::cout << "\n==== pend ====\n";
	// printIteratorVector(pend);
	// std::cout << "\n==== main ====\n";
	// printIteratorVector(main);
	insertPendToMain(pend, main, isOdd);
	// std::cout << BOLD << "\nAfter Insertion: \n" << RESET;
	// std::cout << "\n==== main(updated) ====\n";
	// printIteratorVector(main);
	
	
	// make a copy of values represented by iterators in 'main'
	ContainerType copy;
	typename std::vector<Iterator>::iterator mainIt = main.begin();
	for (; mainIt != main.end(); ++mainIt) {
		Iterator it = next(*mainIt, -pairLevel + 1);
		for (int i = 0; i < pairLevel; ++i) {
			copy.push_back(*it++);
		}
	}

	// update 'ori container' with 'copy' (copy until 'copy.size()' only)
	std::copy(copy.begin(), copy.end(), container.begin());
	
	// std::cout << "\n==== Ori container(updated) ====\n";
	// printContainer(container);


}

template <typename ContainerType> void PmergeMe::sortSequence(ContainerType& container) 
{
	mergeInsertionSort<ContainerType>(container, 1);
}


#endif

