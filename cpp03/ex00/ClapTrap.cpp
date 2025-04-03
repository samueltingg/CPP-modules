/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:15:48 by sting             #+#    #+#             */
/*   Updated: 2025/04/02 18:22:53 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) 
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor called" << std::endl;
}

// Copy Contructor
ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "Copy Constructor called" << std::endl;
}

// Copy Assignment Constructor
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
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
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

std::string ClapTrap::getName() const
{
	return _name;
}

unsigned int	ClapTrap::getHitPoints() const
{
	return _hitPoints;
}
unsigned int	ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " FAILED to attack, " << target << " bcuz it has 0 Hit Points (dead)." << std::endl;
	else if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " FAILED to attack, " << target << " bcuz it has 0 Energy Points." << std::endl;
	else if (_attackDamage == 0)
        std::cout << "ClapTrap " << _name << " attacks " << target << ", but it does no damage!" << std::endl;
	else {
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		// target loses <_attackDamage> hit points
	}	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " did not take any damage bcuz it has 0 Hit Points (dead)" << std::endl;
		return ;
	}
	if (amount > _hitPoints) 
		_hitPoints = 0;
	else 
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " amount of damage. Updated Hit Point: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " FAILED to repair, bcuz it has 0 Hit Points (dead)." << std::endl;
		return ;
	}
	else if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " FAILED to repair, bcuz it has 0 Energy Points." << std::endl;
		return ;
	}
	
	std::cout << "ClapTrap " << _name << " repairs itself, regaining " << amount << " hit points. Updated Hit Point: " << _hitPoints << std::endl;
	_energyPoints -= 1;
	_hitPoints += amount;
}


