/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
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
#include <cstdlib>
#include <stdlib.h>
#include <string.h>


bool	isStrChar(char *literal)
{
	char c = *literal;
	
	if (strlen(literal) == 1)	
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			return true;
	return false;
}


int	checkType(char	*literal)
{
	double doubleValue = 0;
	char	*endPtr = NULL;	

	doubleValue = std::strtod(literal, &endPtr);

	if  (isStrChar(literal)) {
		std::cout << "literal is a char\n";
		return CHAR;
	}
	return DOUBLE;

}

void ScalarConverter::convert(char *literal)
{
	// char charValue;
	// int intValue;
	// float floatValue;
	
	std::cout << "char: " << literal << std::endl
			<< "int: " << std::endl
			<< "float: " << std::endl
			<< "double: " << std::endl;
	
}

