/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:42:43 by sting             #+#    #+#             */
/*   Updated: 2025/03/21 13:05:39 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

void HumanB::attack( void ) {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon) {
	weapon = &newWeapon;
}

