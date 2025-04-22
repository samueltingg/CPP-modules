/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertAndPrint.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:59:36 by sting             #+#    #+#             */
/*   Updated: 2025/04/21 14:11:57 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"


// Returns Overflow type
e_OverflowType checkOverflow(const std::string literal, e_LiteralType type)
{
	if (!(type == INT || type == FLOAT || type == DOUBLE))
		return NO_OVERFLOW;

	double num = strtod(literal.c_str(), NULL);
	if (num == -HUGE_VAL || num == HUGE_VAL)
		return D_OVERFLOW;
	else if (isFloatExeceedingLimits(num))
		return F_OVERFLOW;
	else if (isIntExeceedingLimits(num))
		return I_OVERFLOW;
	else 
		return NO_OVERFLOW;
}

void	printCommonTypes(char c, int i, float f, double d, e_OverflowType overflowType, int decPlacesCount)
{
	// char
	if (!isascii(c))	
		std::cout << "char  : " << IMPOSSIBLE; 
	else if (!isprint(c))
		std::cout << "char  : " << NON_DISPLAYABLE;
	else 
		std::cout << "char  : '" << c << "\'\n";

	// Int
	if (overflowType >= I_OVERFLOW)
		std::cout << "int   : " << IMPOSSIBLE;
	else 
		std::cout << "int   : " << i << std::endl;

	// Float
	if (overflowType >= F_OVERFLOW)
		std::cout << "float : " << IMPOSSIBLE;
	else
		std::cout << std::fixed << std::setprecision(decPlacesCount) << "float : " << f << "f\n";

	// Double
	if (overflowType >= D_OVERFLOW)
		std::cout << "double : " << IMPOSSIBLE;
	else
		std::cout << std::fixed << std::setprecision(decPlacesCount) << "double: " << d << "\n";
}

void	printFromChar(const std::string literal, int decPlacesCount)
{
	char c = literal[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	printCommonTypes(c, i, f, d, NO_OVERFLOW, decPlacesCount);
}

void	printFromInt(const std::string literal, e_OverflowType overflowType, int decPlacesCount)
{
	int i = strtol(literal.c_str(), NULL, 10);
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	printCommonTypes(c, i, f, d, overflowType, decPlacesCount);
}

void	printFromFloat(const std::string literal, e_OverflowType overflowType, int decPlacesCount)
{
	float f = strtof(literal.c_str(), NULL);
	int i = static_cast<int>(f);
	char c = static_cast<char>(f);
	double d = static_cast<double>(f);

	printCommonTypes(c, i, f, d, overflowType, decPlacesCount);
}

void	printFromDouble(const std::string literal, e_OverflowType overflowType, int decPlacesCount)
{

	double d = strtod(literal.c_str(), NULL);
	int i = static_cast<int>(d);
	char c = static_cast<char>(d);
	float f = static_cast<double>(d);

	printCommonTypes(c, i, f, d, overflowType, decPlacesCount);
}

void	convertAndPrint(const std::string literal, e_LiteralType type)
{
	int decPlacesCount = countDecimalPlaces(literal);
	if (decPlacesCount == 0)
		decPlacesCount = 1;
	e_OverflowType overflowType = checkOverflow(literal, type);

	if (type == PSEUDO_FLOAT) {
		std::cout << "char  : impossible\n";
		std::cout << "int   : impossible\n";
		std::cout << "float : " << literal << "\n";
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << "\n"; 	
		return ; 
	} 
	else if (type == PSEUDO_DOUBLE) {
		std::cout << "char  : impossible\n";
		std::cout << "int   : impossible\n";
		std::cout << "float : " << literal << "f" << "\n";
		std::cout << "double: " << literal << "\n";
		return ;
	}
	else if (type == CHAR)
		printFromChar(literal, decPlacesCount);
	else if (type == INT)
		printFromInt(literal, overflowType, decPlacesCount);
	else if (type == FLOAT)
		printFromFloat(literal, overflowType, decPlacesCount);
	else if (type == DOUBLE)
		printFromDouble(literal, overflowType, decPlacesCount);
	else // NECESSARY?? std::cerr << "Invalid literal\n";
		return ;
}

