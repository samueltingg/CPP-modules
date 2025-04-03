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

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) 
	: ClapTrap(name), _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20), _maxHitPoints(100)
{ // ^initialise base class by calling base class constructor
	std::cout << "Constructor called" << std::endl;
}

// Copy Contructor
ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other._name), _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage), _maxHitPoints(other._maxHitPoints)
{ // ^initialise base class by calling base class constructor
	std::cout << "Copy Constructor called" << std::endl;
}

// Copy Assignment Constructor
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this == &other)
		return *this;

	std::cout << "Copy Assignment Operator called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;	

	return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called" << std::endl;
}



void ScavTrap::guardGate()
{

}

