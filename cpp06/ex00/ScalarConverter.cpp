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


e_LiteralType	checkType(std::string literal)
{
	if (isPseudoFloatLiteral(literal)) {
		colorPrint("Type: PSEUDO_FLOAT\n");
		return PSEUDO_FLOAT;
	}
	else if (isPseudoDoubleLiteral(literal)) {
		colorPrint("Type: PSEUDO_DOUBLE\n");
		return PSEUDO_DOUBLE;
	}
	else if (isSinglePrintableChar(literal)) {
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


void	convertAndPrint(std::string literal, e_LiteralType type)
{
	char c;
	int i;
	float f;
	double d;

	if (type == PSEUDO_FLOAT) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << literal << "\n";
		std::cout << "double: " << literal.erase(literal.length() - 1) << "\n";
	}
	else if (type == PSEUDO_DOUBLE) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << literal << "f" << "\n";
		std::cout << "double: " << literal << "\n";
	}
	if (type == CHAR) {
		c = literal[0];

		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (type == INT) {
		i = atoi(literal.c_str());

		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
	}
	else if (type == FLOAT) {
		f = atof(literal.c_str());

		i = static_cast<int>(f);
		c = static_cast<char>(f);
		d = static_cast<double>(f);
	}
	else if (type == DOUBLE) {
		d = strtod(literal.c_str(), NULL);

		i = static_cast<int>(d);
		c = static_cast<char>(d);
		f = static_cast<float>(d);
	}
	else { // NECESSARY?? std::cerr << "Invalid literal\n";
		return ;
	}
	
	if (type == PSEUDO_FLOAT || type == PSEUDO_DOUBLE || !isascii(c))	
		std::cout << "char: impossible\n";
	else if (!isprint(c))
		std::cout << "char: Non displayable\n";
	else 
		std::cout << "char: '" << c << "\'\n";
		
	int decimalPlacesCount = countDecimalPlaces(literal);
	if (decimalPlacesCount == 0)
		decimalPlacesCount = 1;
	std::cout << "int: " << i << std::endl;
	std::cout << std::setprecision(decimalPlacesCount) << "float: " << f << "f\n";
	std::cout << std::setprecision(decimalPlacesCount) << "double: " << d << "\n";
}

void ScalarConverter::convert(std::string literal)
{
	e_LiteralType type = checkType(literal);
	if (type == INVALID) 
		std::cerr << "Input is not a valid literal\n";

	convertAndPrint(literal, type);
		
}

