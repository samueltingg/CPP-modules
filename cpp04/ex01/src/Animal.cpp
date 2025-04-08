/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:53:44 by sting             #+#    #+#             */
/*   Updated: 2025/04/08 11:31:31 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include <iostream>

Animal::Animal()
	: type("")
{
	std::cout << "Animal: Constructor Called" << std::endl;
}

Animal::Animal(const Animal& other)
	: type(other.type)
{
	std::cout << "Animal: Copy Constructor Called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal: Copy Assignment Operator Called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor Called" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}


void Animal::makeSound() const
{
	std::cout << "< Default Animal sound >" << std::endl;
}

