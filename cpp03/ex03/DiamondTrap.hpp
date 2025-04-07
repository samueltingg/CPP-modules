/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:58:51 by sting             #+#    #+#             */
/*   Updated: 2025/04/02 19:15:49 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap { // "Multiple Inheritance"
public: 
	DiamondTrap(std::string name);
	// Copy Contructor
	DiamondTrap(const DiamondTrap& other);
	// Copy Assignment Constructor
	DiamondTrap& operator=(const DiamondTrap& other);
	// Destructor
	~DiamondTrap();
	
	void attack(const std::string& target);
	void whoAmI();

private:
	std::string _name;
};


#endif
