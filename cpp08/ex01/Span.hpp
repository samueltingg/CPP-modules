/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:07:46 by sting             #+#    #+#             */
/*   Updated: 2025/04/28 10:13:46 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define GREY "\033[90m"

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>
#include <numeric>
#include <cstdlib>

class Span {
public:
	// Default Constructor
	Span();
	// Constructor with Parameter
	Span(unsigned int N);
	// Copy Constructor
	Span(const Span& other);
	// Copy Assignment Operator
	Span& operator=(const Span& other);
	// Destructor
	~Span();

	void addNumber(const int num);
	int shortestSpan() const; // return 'unsigned int'?
	int longestSpan() const;
	void addMultipleNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);

	unsigned int getMaxSize() const;

	int	operator[](int index) const;

	class SpanIsFullException : public std::exception {
	public:
		// 'throw()' specifies that func won't throw any exceptions 
        const char* what() const throw() { 
            return "Span is full";
        }

	};
	
	class InsufficientElementsException : public std::exception {
	public:
		// 'throw()' specifies that func won't throw any exceptions 
        const char* what() const throw() { 
            return "Vector is empty or contain only one element.";
        }

	};
	
private:
	std::vector<int> _vector;
	unsigned int _maxSize;
};

std::ostream& operator<<(std::ostream& os, const Span& vector);

#endif
