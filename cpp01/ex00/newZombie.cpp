/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:37:12 by sting             #+#    #+#             */
/*   Updated: 2025/03/20 14:37:34 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

// allocated memory in this case due to not being able to return local defined class instance
Zombie* newZombie(std::string name) {
	Zombie* zombie = new Zombie();
	zombie->setName(name);
	return (zombie);
}
