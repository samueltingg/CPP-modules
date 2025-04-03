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
	: ClapTrap(name)// ^initialise base class by calling base class constructor
{
	std::cout << "ScavTrap: Constructor called" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

// Copy Contructor
ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other._name), _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage), _maxHitPoints(other._maxHitPoints)
{ // ^initialise base class by calling base class constructor
	std::cout << "ScavTrap: Copy Constructor called" << std::endl;
}

// Copy Assignment Constructor
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this == &other)
		return *this;

	std::cout << "ScavTrap: Copy Assignment Operator called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;	

	return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor called" << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
		std::cout << "ScavTrap " << _name << " FAILED to attack, " << target << " bcuz it has 0 Hit Points (dead)." << std::endl;
	else if (_energyPoints == 0)
		std::cout << "ScavTrap " << _name << " FAILED to attack, " << target << " bcuz it has 0 Energy Points." << std::endl;
	else if (_attackDamage == 0)
        std::cout << "ScavTrap " << _name << " attacks " << target << ", but it does no damage!" << std::endl;
	else {
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		// target loses <_attackDamage> hit points
	}	
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gatekeeper mode." << std::endl;
}

