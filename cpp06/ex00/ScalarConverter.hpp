/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:19:16 by sting             #+#    #+#             */
/*   Updated: 2025/04/18 11:24:50 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>


enum e_LiteralType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_FLOAT,
	PSEUDO_DOUBLE,
	INVALID,
};

void colorPrint(const std::string &title);

bool hasDecimalPoint(std::string literal);
bool isPseudoFloatLiteral(std::string literal);
bool isPseudoDoubleLiteral(std::string literal);
bool isSinglePrintableChar(std::string literal);
bool isIntegerLiteral(std::string literal);
bool isFloatLiteral(std::string literal);
bool isDoubleLiteral(std::string literal);

int	countDecimalPlaces(std::string num);

class ScalarConverter {
public:
	static	void convert(std::string literal);

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

