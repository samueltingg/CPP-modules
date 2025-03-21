/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:11:49 by sting             #+#    #+#             */
/*   Updated: 2025/03/21 09:14:51 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void) {

	Zombie *zombieArr;
	int N = 5;
	zombieArr = zombieHorde(N, "bobby");
	for (int i = 0; i < N; i++) {
		zombieArr[i].annouce();
	}
	delete[] zombieArr;
	return (0);
}
