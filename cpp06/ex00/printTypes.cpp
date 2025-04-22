/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printTypes.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:00:32 by sting             #+#    #+#             */
/*   Updated: 2025/04/22 18:09:13 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	printPseudoFloat(std::string literal)
{
	std::cout << "char  : impossible\n";
	std::cout << "int   : impossible\n";
	std::cout << "float : " << literal << "\n";
	std::cout << "double: " << literal.substr(0, literal.length() - 1) << "\n"; 	
}

void	printDoubleFloat(std::string literal)
{
	std::cout << "char  : impossible\n";
	std::cout << "int   : impossible\n";
	std::cout << "float : " << literal << "f" << "\n";
	std::cout << "double: " << literal << "\n";
}

void	printCommonTypes(char c, int i, float f, double d, e_OverflowType overflowType, int decPlacesCount)
{
	// char
	if (overflowType >= C_OVERFLOW || !isascii(c))
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

