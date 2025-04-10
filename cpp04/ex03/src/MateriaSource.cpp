/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:05:49 by sting             #+#    #+#             */
/*   Updated: 2025/04/10 10:10:00 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/MateriaSource.hpp"
#include "../inc/ICharacter.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource: Constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource: Copy Constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this == &other)
		return *this;

	std::cout << "MateriaSource: Copy Assignment Operator called" << std::endl;
	this->type = other.type;

	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: Destructor called" << std::endl;

}


void MateriaSource::learnMateria(AMateria *)
{

}

AMateria *MateriaSource::createMateria(std::string const &type)
{

}




