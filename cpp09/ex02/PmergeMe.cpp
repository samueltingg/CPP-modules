/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:24:46 by sting             #+#    #+#             */
/*   Updated: 2025/05/14 18:25:41 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::_comparisonsCount = 0;

// Constructor
PmergeMe::PmergeMe() 
{
	// std::cout << GREY << "PmergeMe:: Constructor Called" << RESET << std::endl;
}

// Copy Constructor
PmergeMe::PmergeMe(const PmergeMe& other)
{
	std::cout << GREY << "PmergeMe:: Copy Constructor Called" << RESET << std::endl;
	(void)other;
}

// Copy Assignment Operator
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	std::cout << GREY << "PmergeMe:: Copy Assignment Operator Called" << RESET << std::endl;
	
	if (this == &other)
		return *this;
	return *this;
}

// Destructor
PmergeMe::~PmergeMe()
{
	// std::cout << GREY << "PmergeMe:: Destructor Called" << RESET << std::endl;
}

// skips 0 -> 1, 1, 3, 5....
long PmergeMe::_generateJacobNum(long n)
{
	return static_cast<long>(round((pow(2, n + 1) + pow(-1, n)) / 3));
}

int PmergeMe::getComparisonsCount() const
{
	return _comparisonsCount;
}

const char* PmergeMe::InvalidArgumentException::what() const throw() { 
	return "Invalid Argument.";
}

const char* PmergeMe::NumberOutOfRangeException::what() const throw() { 
	return "Number is out of range.";
}

const char* PmergeMe::HasDuplicatesException::what() const throw() { 
	return "Sequence has duplicates";
}


