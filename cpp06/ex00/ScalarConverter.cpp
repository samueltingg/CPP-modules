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


e_LiteralType	checkType(char *literal)
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


void	convertAndPrint(char *literal, e_LiteralType type)
{
	char c;
	int i;
	float f;
	double d;

	// if (type == PSEUDO) {
	//
	// }
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
	else if (type == FLOAT) {
		f = atof(literal);

		i = static_cast<int>(f);
		c = static_cast<char>(f);
		d = static_cast<double>(f);
	}
	else if (type == DOUBLE) {
		d = atof(literal);

		i = static_cast<int>(d);
		c = static_cast<char>(d);
		f = static_cast<float>(d);
	}
	else { // NECESSARY?? std::cerr << "Invalid literal\n";
		return ;
	}
	
	if (type == PSEUDO_FLOAT || type == PSEUDO_DOUBLE || !isAscii(c))	
		std::cout << "char: " << "impossible\n";
	else if (!isDisplayable(c))
		std::cout << "char: " << "Non displayable\n";
	else 
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

