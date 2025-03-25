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

	std::string arr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	int i;
	for (i = 0; i < arrSize; i++) {
		if (arr[i] == level)
			break ;
	}
	
	// "fall through" method
	switch (i) {
		case DEBUG:
			Harl::debug();
		case INFO:
			Harl::info();
		case WARNING:
			Harl::warning();
		case ERROR:
			Harl::error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
	
}


void Harl::debug( void ) {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "[WARNING]" << std::endl;
}

void Harl::error( void ) {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "" << std::endl;
}
