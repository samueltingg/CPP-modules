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

void splitBySpaces(std::string str, std::deque<std::string>& tokens)
{
	std::string::size_type end;
	std::string::size_type start = 0;
	std::string substr;

	while ((end = str.find(" ", start)) != std::string::npos) {
		if (end > start)
			tokens.push_back(str.substr(start, end - start));
		start = end + 1; // set start to character after found ' '
	}

	// if no spaces at all / end with no space
	if (start < str.length())	
	tokens.push_back(str.substr(start));
}

void RPN::printTokens(std::ostream& os)
{
	os << "\n==== Tokens ====\n";
	std::deque<std::string>::size_type i;
	for (i = 0; i < _tokens.size(); ++i) {
		os << "[" << _tokens[i] << "]" << '\n';
	}
}

RPN::RPN(std::string expression) : _tokens(), _stack()
{
	std::cout << GREY << "RPN:: String Constructor Called" << RESET << std::endl;
	
	splitBySpaces(expression, _tokens);
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


