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

void ScalarConverter::convert(const std::string literal)
{
	e_LiteralType type = checkType(literal);
	if (type == INVALID) 
		std::cerr << "Input is not a valid literal\n";

	convertAndPrint(literal, type);
		
}

