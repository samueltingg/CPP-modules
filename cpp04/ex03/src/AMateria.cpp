/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:50:18 by sting             #+#    #+#             */
/*   Updated: 2025/04/09 17:42:28 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"
#include <iostream>

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
	
}

