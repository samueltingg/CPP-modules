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

#include <vector>
#include <iostream>

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
	void fillSpan();

	unsigned int getMaxSize() const;

	int	operator[](int index) const;

	class SpanIsFullException : public std::exception {
	public:
		// 'throw()' specifies that func won't throw any exceptions 
        const char* what() const throw() { 
            return "Span is full";
        }

	};
	
	class NoSpanFoundException : public std::exception {
	public:
		// 'throw()' specifies that func won't throw any exceptions 
        const char* what() const throw() { 
            return "No span found. No numbers stored.";
        }

	};

private:
	std::vector<int> _vector;
	unsigned int _maxSize;
};

std::ostream& operator<<(std::ostream& os, const Span& vector);

#endif
