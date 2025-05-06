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


void PmergeMe::sortSequence()
{

}
	
void PmergeMe::printVector()
{
	std::vector<int>::const_iterator it = _sequence.begin();

	for (; it != _sequence.end(); ++it) {
		std::cout << *it << '\n';
	}

}

const char* PmergeMe::InvalidArgumentException::what() const throw() { 
	return "Invalid Argument.";
}

const char* PmergeMe::NumberOutOfRangeException::what() const throw() { 
	return "Number is out of range.";
}

