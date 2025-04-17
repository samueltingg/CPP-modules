/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:19:16 by sting             #+#    #+#             */
/*   Updated: 2025/04/17 11:16:02 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>


enum {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
};

class ScalarConverter {
public:
	static	void convert(char *literal);

private:
	// Set as private to prevent class to be instanciated: 
	// Constructor
	ScalarConverter(std::string name, int grade);
	// Copy Constructor
	ScalarConverter(const ScalarConverter& other);
	// Copy Assignment Operator
	ScalarConverter& operator=(const ScalarConverter& other);
	// Destructor
	~ScalarConverter();
};

#endif

