/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:19:37 by sting             #+#    #+#             */
/*   Updated: 2025/04/08 11:44:39 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include <iostream>

Dog::Dog()
	: Animal() 
{
	std::cout << "Dog: Constructor Called" << std::endl;
	Animal::type = "Dog";
}

Dog::Dog(const Dog& other)
	: Animal()
{
	std::cout << "Dog: Copy Constructor Called" << std::endl;
	this->type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog: Copy Assignment Operator Called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor Called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "< Woof! Woof! Woof! >" << std::endl;
}
