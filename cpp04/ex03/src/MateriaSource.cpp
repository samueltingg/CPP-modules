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

	for (int i = 0; i < _maxMateriaCount; ++i) {
		_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource: Copy Constructor called" << std::endl;

	for (int i = 0; i < _maxMateriaCount; ++i) {
		this->_inventory[i] = NULL; // init to NULL first
		if (other._inventory[i])
			this->_inventory[i] = (other._inventory[i])->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this == &other)
		return *this;

	std::cout << "MateriaSource: Copy Assignment Operator called" << std::endl;

	for (int i = 0; i < _maxMateriaCount; ++i) {
		delete this->_inventory[i];
		if (other._inventory[i])
			this->_inventory[i] = (other._inventory[i])->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: Destructor called" << std::endl;

	for (int i = 0; i < _maxMateriaCount; ++i) {
		if (_inventory[i])
			delete _inventory[i];
	}
}


void MateriaSource::learnMateria(AMateria *m)
{
	AMateria *copy = m->clone();

	for (int i = 0; i < _maxMateriaCount; ++i) {
		if (!_inventory[i]) {
			_inventory[i] = copy;
			break ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{

}




