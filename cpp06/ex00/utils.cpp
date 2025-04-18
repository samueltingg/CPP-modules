/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:20:51 by sting             #+#    #+#             */
/*   Updated: 2025/04/18 11:25:05 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <string.h>
#include <stdlib.h>


void colorPrint(const std::string &title) {
	std::cout << "\033[36m"<< "\033[1m" << title << "\033[0m"
		<< std::endl;
}

bool isAscii(char c)
{
	if (c >= 0 && c <= 127)
		return (true);
	return (false);
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


// bool isPseudoLiteral(char *literal)
// {
// 	const char *arr[] = {"inff", "-inff", "+inff","inf", "-inf", "+inf", "nan", "nanf"};
//
//
// 	for (int i = 0; i < 6; i++) {
// 		if (!strcmp(literal, arr[i]))
// 			return true;
// 	}
// 	return false;
// }

bool isPseudoFloatLiteral(char *literal)
{
	const char *arr[4] = {"inff", "-inff", "+inff", "nanf"};
	
	
	for (int i = 0; i < 4; i++) {
		if (!strcmp(literal, arr[i]))
			return true;
	}
	return false;
}

bool isPseudoDoubleLiteral(char *literal)
{
	const char *arr[4] = {"inf", "-inf", "+inf", "nan"};
	
	
	for (int i = 0; i < 4; i++) {
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


