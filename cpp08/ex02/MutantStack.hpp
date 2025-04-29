/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:36:20 by sting             #+#    #+#             */
/*   Updated: 2025/04/29 10:39:51 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define GREY "\033[90m"

#include <stack>
#include <deque>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>
#include <numeric>
#include <cstdlib>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	// Default Constructor
	MutantStack();
	// Copy Constructor
	MutantStack(const MutantStack& other);
	// Copy Assignment Operator
	MutantStack& operator=(const MutantStack& other);
	// Destructor
	~MutantStack();
	
	// deque, list, vector has all these iterators
	// 'container_type': underlying container type	
	typedef	 typename std::stack<T>::container_type::iterator iterator;
	typedef	 typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef	 typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef	 typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	
	iterator begin() { return this->c.begin(); };
	iterator end() { return this->c.end(); };
	iterator rbegin() { return this->c.rbegin(); };
	iterator rend() { return this->c.rend(); };
};

template <typename T>
MutantStack<T>::MutantStack() 
	: std::stack<T>()
{
	std::cout << GREY << "MutantStack:: Default Constructor Called" << RESET << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other)
	: std::stack<T>()  
{
	std::cout << GREY << "MutantStack:: Copy Constructor Called" << RESET << std::endl;

	std::stack<T> temp = other;

	while (!temp.empty()) {
		this->push(temp.top());
		temp.pop();
	}
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
	std::cout << GREY << "MutantStack:: Copy Assignment Operator Called" << RESET << std::endl;
	
	if (this == &other)
		return *this;

	// Clear current stack	
	while (!this->empty())
		this->pop();

	std::stack<T> temp = other;
	while (!temp.empty()) {
		this->push(temp.top());
		temp.pop();
	}

	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << GREY << "MutantStack:: Destructor Called" << RESET << std::endl;
}


#endif
