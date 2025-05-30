/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:11:15 by sting             #+#    #+#             */
/*   Updated: 2025/04/10 11:21:22 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Character.hpp"

Character::Character(std::string name)
	: _name(name)
{
	std::cout << "Character: Constructor called (name: " << name << ")" << std::endl;

	for (int i = 0; i < maxMateriaCount; ++i) {
		_inventory[i] = NULL;
	}
}

Character::Character(const Character& other)
	: _name(other._name)
{
	std::cout << "Character: Copy Constructor called" << std::endl;
	for (int i = 0; i < maxMateriaCount; ++i) {
		this->_inventory[i] = NULL; // init to NULL first
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
		if (other._inventory[i])
			this->_inventory[i] = (other._inventory[i])->clone();
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character: Destructor called (name: " << _name << ")" << std::endl;

	for (int i = 0; i < maxMateriaCount; ++i) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const & Character::getName() const
{
	return (_name);
}

// add a Materia in the first empty spot in the arr
void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < maxMateriaCount; ++i) {
		if (!_inventory[i]) {
			std::cout << "equip: added \"" << m->getType() << "\" into inventory." << std::endl;
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "equip: Fail to add Materia as inventory is full." << std::endl;
}

// doesn't not free (save ptr before calling unequip)
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= maxMateriaCount) {
		std::cout << "unequip: Invalid Index, not within range." << std::endl;
	}
	if (!_inventory[idx])
		std::cout << "unequip: Nothing done. Inventory is empty at Index: " << idx << std::endl;
	else {
		std::cout << "unequip: removed \"" << _inventory[idx]->getType() << "\" from inventory." << std::endl;
		_inventory[idx] = NULL;

	}
}

void Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else 
		std::cout << "Charater::use: Nothing done. Inventory is empty at Index: " << idx << std::endl;
}

const AMateria *Character::getMateriaFromInventory(int idx)
{
	return (_inventory[idx]);
}


