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

RPN::RPN() : _tokens()
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
	std::deque<std::string>::const_iterator it = _tokens.begin();

	for (; it != _tokens.end(); ++it) {
		os << "[" << *it << "]" << '\n';
	}
}

bool isExpressionValid(const std::string& expression, std::deque<std::string>& tokens)
{
	if (expression.find_first_not_of("1234567890+-*/ ") != std::string::npos)
		return false;
	return true;	
}

RPN::RPN(std::string expression) : _tokens()
{
	std::cout << GREY << "RPN:: String Constructor Called" << RESET << std::endl;
	
	if (!isExpressionValid(expression))
		throw RPN::InvalidTokenException();

	splitBySpaces(expression, _tokens);
}

RPN::RPN(const RPN& other) : _tokens(other._tokens)
{
	std::cout << GREY << "RPN:: Copy Constructor Called" << RESET << std::endl;
}

RPN& RPN::operator=(const RPN& other)
{
	std::cout << GREY << "RPN:: Copy Assignment Operator Called" << RESET << std::endl;
	
	if (this == &other)
		return *this;
	_tokens = other._tokens;
	return *this;
}

RPN::~RPN()
{
	std::cout << GREY << "RPN:: Destructor Called" << RESET << std::endl;
}



operatorType getOperatorType(const std::string& str) 
{
	if (str == "+") 
		return PLUS;
	else if (str == "-") 
		return MINUS;
	else if (str == "*") 
		return TIMES;
	else if (str == "/") 
		return DIVIDE;
	else
		return NOT_OP;
}

int stringToInt(const std::string& str)
{
	int num;
	
	// use atoi as confirm 1 digit

}

int RPN::calcExpression()
{
	std::stack<int> stack;
	std::deque<std::string>::const_iterator it = _tokens.begin();
	operatorType opType;

	for (; it != _tokens.end(); ++it) {
		if (opType != NOT_OP) {
			
		}
		else {
			
		}		

	}

}


const char* RPN::InvalidTokenException::what() const throw() { 
	return "Invalid Token.";
}


