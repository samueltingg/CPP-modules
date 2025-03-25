/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:37:01 by sting             #+#    #+#             */
/*   Updated: 2025/03/25 09:37:06 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"
/*
When creating apointer to a member function, must specify class name 
as pointer type includes class name
*/
void	Harl::complain( std::string level ) {
	const t_commentType arr[] = {
		{"DEBUG", &Harl::debug}, 
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error},
	};

	int arrSize = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < arrSize; i++) {
		if (arr[i].type == level) {
			arr[i].comment(); // need to dereference since it's a function ptr? 
			return ;
		}
	} 
}


void Harl::debug( void ) {
	std::cout << "[DEBUG]" << std::endl;
}

void Harl::info( void ) {
	std::cout << "[INFO]" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "[WARNING]" << std::endl;
}

void Harl::error( void ) {
	std::cout << "[ERROR]" << std::endl;
}
