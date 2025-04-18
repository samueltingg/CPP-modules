/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:22:08 by sting             #+#    #+#             */
/*   Updated: 2025/04/17 11:23:54 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>


ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter:: Constructor Called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	std::cout << "ScalarConverter:: Copy Constructor Called" << std::endl;
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	std::cout << "ScalarConverter:: Copy Assignment Operator Called" << std::endl;
	
	if (this == &other)
		return *this;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Bureaucrat:: Destructor Called" << std::endl;
}


bool isDisplayable(char c)
{
	if (c >= 32 && c <= 126)
		return true;
	return false;
}

bool	hasDecimalPoint(char *literal)
{
	if (!literal)
		return false;
	for (int i = 0; literal[i]; ++i) {
		if (literal[i] == '.')
			return true;
	}
	return false;
}


bool isPseudoLiteral(char	*literal)
{
	const char *arr[5] = {"-inff", "+inff", "-inf", "+inf", "nan"};
	
	
	for (int i = 0; i < 5; i++) {
		if (!strcmp(literal, arr[i]))
			return true;
	}
	return false;
}

bool	isSinglePrintableChar(char *literal)
{
	if (!literal)
		return false;
	char c = *literal;

	if (strlen(literal) == 1)	
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			return true;
	return false;
}

bool isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

bool isIntegerLiteral(char	*literal) 
{
	int i = 0;

	if (literal[0] == '-')
		i++;
	for (; literal[i]; i++) {
		if (!isDigit(literal[i]))
			return false;
	} 
	return true;
}

bool isFloatLiteral(char *literal)
{
	if (!hasDecimalPoint(literal))
		return false;

	char	*endPtr = NULL;	
	strtof(literal, &endPtr);

	if (endPtr[0] == 'f' && endPtr[1] == '\0')
		return true;
	return false;
}

bool isDoubleLiteral(char *literal)
{
	if (!hasDecimalPoint(literal))
		return false;

	char	*endPtr = NULL;	
	strtof(literal, &endPtr);

	if (endPtr[0] == '\0')
		return true;
	return false;
}



e_LiteralType	checkType(char *literal)
{
	if (isPseudoLiteral(literal)) {
		colorPrint("Type: PSEUDO\n");
		return PSEUDO;
	}
	if (isSinglePrintableChar(literal)) {
		colorPrint("Type: CHAR\n");
		return CHAR;
	}
	else if (isIntegerLiteral(literal)) {
		colorPrint("Type: INT\n");
		return INT;
	}
	else if (isFloatLiteral(literal)) {
		colorPrint("Type: FLOAT\n");
		return FLOAT;
	}
	else if (isDoubleLiteral(literal)) {
		colorPrint("Type: DOUBLE\n");
		return DOUBLE;
	}
	else {
		colorPrint("Type: INVALID\n");
		return INVALID;
	}
}


void	convertAndPrint(char *literal, e_LiteralType type)
{
	char c;
	int i;
	float f;
	double d;

	if (type == CHAR) {
		c = literal[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (type == INT) {
		i = atoi(literal);
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);

	}
	else { // NECESSARY?? std::cerr << "Invalid literal\n";
		return ;
	}

	std::cout << "char: '" << c << "\'\n";
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f\n";
	std::cout << std::fixed << std::setprecision(1) << "double: " << d << "\n";
}

void ScalarConverter::convert(char *literal)
{
	// char charValue;
	// int intValue;
	// float floatValue;
	e_LiteralType type = checkType(literal);
	if (type == INVALID) 
		std::cerr << "Input is not a valid literal\n";

	convertAndPrint(literal, type);
		
}

