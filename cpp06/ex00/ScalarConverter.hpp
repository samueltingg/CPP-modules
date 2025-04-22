/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:19:16 by sting             #+#    #+#             */
/*   Updated: 2025/04/22 18:09:48 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <limits>
#include <cmath>

#define IMPOSSIBLE "impossible\n"
#define NON_DISPLAYABLE "Non displayable\n"

enum e_LiteralType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_FLOAT,
	PSEUDO_DOUBLE,
	INVALID,
};

enum e_OverflowType {
	NO_OVERFLOW,
	C_OVERFLOW,
	I_OVERFLOW,
	F_OVERFLOW,
	D_OVERFLOW
};

void colorPrint(const std::string &title);

// Check Functions
bool hasDecimalPoint(const std::string literal);
bool isPseudoFloatLiteral(const std::string literal);
bool isPseudoDoubleLiteral(const std::string literal);
bool isSinglePrintableChar(const std::string literal);
bool isIntegerLiteral(const std::string literal);
bool isFloatLiteral(const std::string literal);
bool isDoubleLiteral(const std::string literal);
int	countDecimalPlaces(const std::string num);
bool	isCharExeceedingLimits(const double num);
bool	isIntExeceedingLimits(const double num) ;
bool	isFloatExeceedingLimits(const double num) ;
e_OverflowType checkOverflow(const std::string literal, e_LiteralType type);

// checkType
e_LiteralType	checkType(std::string literal);

// checkOverflow
e_OverflowType checkOverflow(const std::string literal, e_LiteralType type);

// printTypes
void	printPseudoFloat(std::string literal);
void	printDoubleFloat(std::string literal);
void	printCommonTypes(char c, int i, float f, double d, e_OverflowType overflowType, int decPlacesCount);
void	printFromChar(const std::string literal, int decPlacesCount);
void	printFromInt(const std::string literal, e_OverflowType overflowType, int decPlacesCount);
void	printFromFloat(const std::string literal, e_OverflowType overflowType, int decPlacesCount);
void	printFromDouble(const std::string literal, e_OverflowType overflowType, int decPlacesCount);

// convertAndPrint
void	convertAndPrint(const std::string literal, e_LiteralType type);

class ScalarConverter {
public:
	static	void convert(const std::string literal);

private:
	// Set as private to prevent class to be instanciated: 
	// Default Constructor
	ScalarConverter();
	// Constructor with Parameters

	// Copy Constructor
	ScalarConverter(const ScalarConverter& other);
	// Copy Assignment Operator
	ScalarConverter& operator=(const ScalarConverter& other);
	// Destructor
	~ScalarConverter();
};

#endif

