/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:05:14 by sting             #+#    #+#             */
/*   Updated: 2025/03/20 14:31:44 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {}

Zombie::~Zombie(void) {
	std::cout << name << ": destroyed" << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}

void Zombie::annouce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


