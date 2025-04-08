/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:06:15 by sting             #+#    #+#             */
/*   Updated: 2025/04/08 17:06:35 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
	: type("")
{
	std::cout << "WrongAnimal: Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
	: type(other.type)
{
	std::cout << "WrongAnimal: Copy Constructor Called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal: Copy Assignment Operator Called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor Called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}


void WrongAnimal::makeSound() const
{
	std::cout << "< Default WrongAnimal sound >" << std::endl;
}

