/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:45:58 by sting             #+#    #+#             */
/*   Updated: 2025/05/05 10:46:37 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _tokens(), _stack()
{
	std::cout << GREY << "RPN:: Constructor Called" << RESET << std::endl;
}


RPN::RPN(std::string fileName) : _tokens(), _stack()

{
	std::cout << GREY << "RPN:: String Constructor Called" << RESET << std::endl;
}

RPN::RPN(const RPN& other) : _tokens(other._tokens), _stack(other._stack)

{
	std::cout << GREY << "RPN:: Copy Constructor Called" << RESET << std::endl;
}

RPN& RPN::operator=(const RPN& other)
{
	std::cout << GREY << "RPN:: Copy Assignment Operator Called" << RESET << std::endl;
	
	if (this == &other)
		return *this;
	_tokens = other._tokens;
	_stack = other._stack;
	return *this;
}

RPN::~RPN()
{
	std::cout << GREY << "RPN:: Destructor Called" << RESET << std::endl;
}

const char* RPN::ErrorOpeningFileException::what() const throw() { 
	return "Error opening file.";
}

std::ostream& operator<<(std::ostream& os, RPN& rpn)
{

	return os;
}
