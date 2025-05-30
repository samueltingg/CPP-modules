/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:20:51 by sting             #+#    #+#             */
/*   Updated: 2025/04/21 13:23:02 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void colorPrint(const std::string &title) {
	std::cout << "\033[36m"<< "\033[1m" << title << "\033[0m"
		<< std::endl;
}

bool	hasDecimalPoint(const std::string literal)
{
	if (literal.empty())
		return false;

	size_t decimalPos = literal.find('.');
	if (decimalPos == std::string::npos)
		return false;
	return true;
}

bool isPseudoFloatLiteral(const std::string literal)
{
	const char *arr[4] = {"inff", "-inff", "+inff", "nanf"};
	
	
	for (int i = 0; i < 4; i++) {
		if (literal == arr[i])
			return true;
	}
	return false;
}

bool isPseudoDoubleLiteral(const std::string literal)
{
	const char *arr[4] = {"inf", "-inf", "+inf", "nan"};
	
	
	for (int i = 0; i < 4; i++) {
		if (literal == arr[i])
			return true;
	}
	return false;
}

bool	isSinglePrintableChar(const std::string literal)
{
	if (literal.empty())
		return false;
	char c = literal[0];

	if (literal.length() == 1 && isalpha(c))
		return true;
	return false;
}

bool isIntegerLiteral(const std::string literal) 
{
	int i = 0;
	if (checkOverflow(literal, INT) >= I_OVERFLOW)
		return false;
	if (literal[0] == '-')
		i++;
	for (; literal[i]; i++) {
		if (!isdigit(literal[i]))
			return false;
	} 
	return true;
}

bool isFloatLiteral(const std::string literal)
{
	if (!hasDecimalPoint(literal))
		return false;
	if (literal.find_first_of("eE") != std::string::npos)
		return false;

	char	*endPtr = NULL;	
	strtof(literal.c_str(), &endPtr);

	if (endPtr[0] == 'f' && endPtr[1] == '\0')
		return true;
	return false;
}

bool isDoubleLiteral(const std::string literal)
{
	if (!hasDecimalPoint(literal))
		return false;
	if (checkOverflow(literal, DOUBLE) == D_OVERFLOW)
		return false;
	if (literal.find_first_of("eE") != std::string::npos)
		return false;

	char	*endPtr = NULL;
	strtod(literal.c_str(), &endPtr);

	if (endPtr[0] == '\0')
		return true;
	return false;
}


int	countDecimalPlaces(const std::string num)
{
	size_t decimalPos = num.find('.');
	if (decimalPos == std::string::npos)
		return 0;
	if (num[num.length() - 1] == 'f')
		return (num.length() - 1 - decimalPos -1);
	return (num.length() - decimalPos - 1);
}

bool	isCharExeceedingLimits(const double num) 
{
	if (num < std::numeric_limits<signed char>::min() || num > std::numeric_limits<signed char>::max())
		return true;
	return false;
}

bool	isIntExeceedingLimits(const double num) 
{
	if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		return true;
	return false;
}

bool	isFloatExeceedingLimits(const double num) 
{
	// use 'lowest' instead of 'min'
	if (num < -std::numeric_limits<float>::max() || num > std::numeric_limits<float>::max())
		return true;
	return false;
}

