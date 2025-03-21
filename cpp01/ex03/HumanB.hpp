/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:42:00 by sting             #+#    #+#             */
/*   Updated: 2025/03/21 13:05:30 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP 

#include "Weapon.hpp"

class HumanB {
public: 
	// constructor overloading
	HumanB( const std::string& name ) : name(name), weapon(nullptr) {};
	HumanB( const std::string& name, Weapon& weapon ) : name(name), weapon(&weapon) {};

	~HumanB() {};
	void	attack( void );
	void	setWeapon(Weapon& newWeapon);

private:
	std::string	name;
	Weapon		*weapon; // A Pointer must be used instead of a Reference as `weapon` may or might not be initialised
};

#endif
