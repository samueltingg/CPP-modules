/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:50:18 by sting             #+#    #+#             */
/*   Updated: 2025/04/09 18:03:34 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/AMateria.hpp"
#include "../inc/ICharacter.hpp"

AMateria::AMateria(std::string const & type)
	: type(type)
{
	std::cout << "AMateria: Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
	: type(other.type)
{
	std::cout << "AMateria: Copy Constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this == &other)
		return *this;

	std::cout << "AMateria: Copy Assignment Operator called" << std::endl;
	this->type = other.type;

	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria: Destructor called" << std::endl;

}
std::string const & AMateria::getType() const //Returns the materia type
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria's `use` function called on " << target.getName() << std::endl;

}

