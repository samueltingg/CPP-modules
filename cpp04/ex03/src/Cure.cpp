/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:54:04 by sting             #+#    #+#             */
/*   Updated: 2025/04/09 17:55:48 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Cure.hpp"
#include "../inc/ICharacter.hpp"

Cure::Cure()
	: AMateria("cure") 
{
	std::cout << "Cure: Constructor called" << std::endl;
}

Cure::Cure(const Cure& other)
	: AMateria(other.type)
{
	std::cout << "Cure: Copy Constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	if (this == &other)
		return *this;

	std::cout << "Cure: Copy Assignment Operator called" << std::endl;
	this->type = other.type;
	
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure: Destructor called" << std::endl;

}

Cure* Cure::clone() const
{
	return new Cure(*this); // call copy constructor
}


void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

