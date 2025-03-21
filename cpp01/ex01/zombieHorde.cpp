/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHordie.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:14:44 by sting             #+#    #+#             */
/*   Updated: 2025/03/21 09:09:06 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

	Zombie	*zombieArr = new Zombie[N];
	
	for (int i = 0; i < N; i++) {
		zombieArr[i].setName(name);
	}
	return (zombieArr); // same as `&zombieArr[0]`
}
