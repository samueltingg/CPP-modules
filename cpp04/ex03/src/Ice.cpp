/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:40:40 by sting             #+#    #+#             */
/*   Updated: 2025/04/09 17:53:46 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"
#include <iostream>

Ice::Ice()
	: AMateria("ice") 
{
	std::cout << "Ice: Constructor called" << std::endl;
}

Ice::Ice(const Ice& other)
	: AMateria(other.type)
{
	std::cout << "Ice: Copy Constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	if (this == &other)
		return *this;

	std::cout << "Ice: Copy Assignment Operator called" << std::endl;
	this->type = other.type;
}

Ice::~Ice()
{
	std::cout << "Ice: Destructor called" << std::endl;

}

Ice* Ice::clone() const
{
	Ice	*newIce = new Ice(*this); // call copy constructor

	return newIce;
}


void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName << " *" << std::endl;
}

