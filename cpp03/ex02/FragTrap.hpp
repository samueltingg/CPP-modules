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

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap(std::string name);
	// Copy Contructor
	FragTrap(const FragTrap& other);
	// Copy Assignment Constructor
	FragTrap& operator=(const FragTrap& other);
	// Destructor
	~FragTrap();
	
	void attack(const std::string& target);
	void highFivesGuys();

};


#endif
