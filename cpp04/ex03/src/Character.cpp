/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:11:15 by sting             #+#    #+#             */
/*   Updated: 2025/04/10 10:13:01 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Character.hpp"

Character::Character(std::string name)
	: _name(name)
{
	std::cout << "Character: Constructor called" << std::endl;

	for (int i = 0; i < maxMateriaCount; ++i) {
		_inventory[i] = nullptr;
	}
}

Character::Character(const Character& other)
	: _name(other._name)
{
	std::cout << "Character: Copy Constructor called" << std::endl;
	for (int i = 0; i < maxMateriaCount; ++i) {
		if (other._inventory[i])
			this->_inventory[i] = (other._inventory[i])->clone();
	}
}

Character& Character::operator=(const Character& other)
{
	if (this == &other)
		return *this;

	std::cout << "Character: Copy Assignment Operator called" << std::endl;
	this->_name = other._name;

	for (int i = 0; i < maxMateriaCount; ++i) {

		delete this->_inventory[i];
		this->_inventory[i];
		if (other._inventory[i])
			this->_inventory[i] = (other._inventory[i])->clone();
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character: Destructor called" << std::endl;

	for (int i = 0; i < maxMateriaCount; ++i) {
		delete _inventory[i];
	}
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{

}

void Character::unequip(int idx)
{

}

void Character::use(int idx, Character& target)
{

}

