/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:25:00 by sting             #+#    #+#             */
/*   Updated: 2025/04/08 11:43:25 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include <iostream>

Cat::Cat()
	: Animal() 
{
	std::cout << "Cat: Constructor Called" << std::endl;
	Animal::type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& other)
	: Animal()
{
	std::cout << "Cat: Copy Constructor Called" << std::endl;
	this->type = other.type;
	this->_brain = new Brain(*other._brain); // calls Brain's copy constructor

}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat: Copy Assignment Operator Called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;

	delete _brain;
	_brain = new Brain(*other._brain);	
	
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor Called" << std::endl;
	delete _brain;
}

void Cat::makeSound() const
{
	std::cout << "< Meow Meow Meow >" << std::endl;
}

const Brain *Cat::getBrainAddress() const
{
	return (_brain);
}

