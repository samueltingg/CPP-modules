/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:42:47 by sting             #+#    #+#             */
/*   Updated: 2025/03/21 13:00:41 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP 

#include "Weapon.hpp"

class HumanA {
public:
	HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {};

	~HumanA() {};
	void	attack( void );

private:
	std::string	name;
	Weapon&		weapon; // a Reference is used in this case instead of a Pointer because it will always be initialised by the constructor
};

#endif
