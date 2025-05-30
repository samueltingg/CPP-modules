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

void ScalarConverter::convert(const std::string literal)
{
	e_LiteralType type = checkType(literal);
	if (type == INVALID) 
		std::cerr << "Input is not a valid literal\n";

	convertAndPrint(literal, type);
		
}

