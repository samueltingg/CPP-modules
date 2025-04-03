/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:58:49 by sting             #+#    #+#             */
/*   Updated: 2025/04/02 19:16:44 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) 
	: ClapTrap(name)// ^initialise base class by calling base class constructor
{
	std::cout << "FragTrap: Constructor called" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

// Copy Contructor
FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other._name)
{ // ^initialise base class by calling base class constructor
	std::cout << "FragTrap: Copy Constructor called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;

}

// Copy Assignment Constructor
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this == &other)
		return *this;

	std::cout << "FragTrap: Copy Assignment Operator called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;	

	return *this;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor called" << std::endl;
}


void FragTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
		std::cout << "FragTrap " << _name << " FAILED to attack, " << target << " bcuz it has 0 Hit Points (dead)." << std::endl;
	else if (_energyPoints == 0)
		std::cout << "FragTrap " << _name << " FAILED to attack, " << target << " bcuz it has 0 Energy Points." << std::endl;
	else if (_attackDamage == 0)
        std::cout << "FragTrap " << _name << " attacks " << target << ", but it does no damage!" << std::endl;
	else {
		_energyPoints--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		// target loses <_attackDamage> hit points
	}	
}

void FragTrap::highFivesGuys()
{
	std::cout << "" << std::endl;
}


