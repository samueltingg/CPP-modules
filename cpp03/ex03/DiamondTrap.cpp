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

#include <iostream>
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) 
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap: Constructor called" << std::endl;
	/*_name = name;*/
	/*_hitPoints = 100;*/
	/*_energyPoints = 100;*/
	/*_attackDamage = 30;*/
}

// Copy Contructor
DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other._name+ "_clap_name"), ScavTrap(other._name), FragTrap(other._name)

{ // ^initialise base class by calling base class constructor
	std::cout << "DiamondTrap: Copy Constructor called" << std::endl;
	/*_name = other._name;*/
	/*_hitPoints = other._hitPoints;*/
	/*_energyPoints = other._energyPoints;*/
	/*_attackDamage = other._attackDamage;*/

}

// Copy Assignment Constructor
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this == &other)
		return *this;

	std::cout << "DiamondTrap: Copy Assignment Operator called" << std::endl;
	/*this->_name = other._name;*/
	/*this->_hitPoints = other._hitPoints;*/
	/*this->_energyPoints = other._energyPoints;*/
	/*this->_attackDamage = other._attackDamage;	*/

	return *this;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Destructor called" << std::endl;
}


void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->getName() << "ClapTrap name: " << this->getName()<< std::endl;
}


