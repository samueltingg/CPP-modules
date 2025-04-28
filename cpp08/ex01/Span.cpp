/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:08:17 by sting             #+#    #+#             */
/*   Updated: 2025/04/28 10:13:38 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _vector(), _maxSize(0) 
{
	std::cout << GREY << "Span:: Constructor Called" << RESET << std::endl;
}

Span::Span(unsigned int N) : _vector(), _maxSize(N)
{
	std::cout << GREY << "Span:: Unsigned Int Constructor Called" << RESET << std::endl;
}

Span::Span(const Span& other) : _vector(other._vector), _maxSize(other._maxSize)
{
	std::cout << GREY << "Span:: Copy Constructor Called" << RESET << std::endl;
}

Span& Span::operator=(const Span& other)
{
	std::cout << GREY << "Span:: Copy Assignment Operator Called" << RESET << std::endl;
	
	if (this == &other)
		return *this;
	_vector = other._vector;
	_maxSize = other._maxSize;
	return *this;
}

Span::~Span()
{
	std::cout << GREY << "Span:: Destructor Called" << RESET << std::endl;
}

void Span::addNumber(const int num)
{
	if (_vector.size() >= _maxSize)
		throw Span::SpanIsFullException();
	_vector.push_back(num);
}
	
// void Span::addMultipleNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
// {
// 	std::vector<int>::iterator it = begin;
//
// 	for (it = begin; it < end; it++) {
//
// 	}
// }

//methods used: sort, adjacent_difference
int Span::shortestSpan() const // return 'unsigned int'?
{
	if (_vector.size() < 2)
		throw InsufficientElementsException();

	std::vector<int> copy = _vector;
	std::sort(copy.begin(), copy.end());
	std::adjacent_difference(copy.begin(), copy.end(), copy.begin());
	std::vector<int>::const_iterator minIt = std::min_element(copy.begin(), copy.end());
	
	return abs(*minIt);
}

int Span::longestSpan() const
{
	if (_vector.size() < 2)
		throw InsufficientElementsException();
	std::vector<int>::const_iterator maxIt = std::max_element(_vector.begin(), _vector.end());
	std::vector<int>::const_iterator minIt = std::min_element(_vector.begin(), _vector.end());

	return (*maxIt - *minIt);
}

unsigned int Span::getMaxSize() const
{
	return _maxSize;
}


int	Span::operator[](int index) const
{
	return _vector[index];
}

std::ostream& operator<<(std::ostream& os, const Span& vector)
{
	for (size_t i = 0; i < vector.getMaxSize(); i++) {
		os << i << ": " << vector[i] << '\n';
	}
	return os;
}

