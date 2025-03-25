/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:36:43 by sting             #+#    #+#             */
/*   Updated: 2025/03/25 09:36:51 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << "Error: Program only takes in 1 argument" << std::endl;
		return (1);
	}
	Harl::complain(argv[1]);	
	return (0);	
}
