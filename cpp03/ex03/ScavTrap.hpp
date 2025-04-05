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

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap(std::string name);
	// Copy Contructor
	ScavTrap(const ScavTrap& other);
	// Copy Assignment Constructor
	ScavTrap& operator=(const ScavTrap& other);
	// Destructor
	~ScavTrap();
	
	void attack(const std::string& target);
	void guardGate();

};


#endif
