/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:05:14 by sting             #+#    #+#             */
/*   Updated: 2025/03/24 16:18:15 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {}

Zombie::~Zombie(void) {
	std::cout << _name << ": destroyed" << std::endl;
}

void Zombie::setName(std::string name) {
	this->_name = name;
}

void Zombie::annouce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


