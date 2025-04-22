/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:27:54 by sting             #+#    #+#             */
/*   Updated: 2025/04/22 18:34:31 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Serializer()
{
	std::cout << "Serializer:: Constructor Called" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
	std::cout << "Serializer:: Copy Constructor Called" << std::endl;
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	std::cout << "Serializer:: Copy Assignment Operator Called" << std::endl;
	
	if (this == &other)
		return *this;
	return *this;
}

Serializer::~Serializer()
{
	std::cout << "Bureaucrat:: Destructor Called" << std::endl;
}

// It takes a pointer and converts it to the unsigned integer type uintptr_t.
uintptr_t Serializer::serialize(Data* ptr)
{

}

// It takes an unsigned integer parameter and converts it to a pointer to Data.
Data* Serializer::deserialize(uintptr_t raw)
{

}

