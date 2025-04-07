/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:15:56 by sting             #+#    #+#             */
/*   Updated: 2025/04/02 18:22:07 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define GREY    "\033[90m"

void printSection(const std::string& title) {
    std::cout << CYAN << BOLD << "\n=== " << title << " ===" << RESET << std::endl;
}

int main() {
    printSection("Testing Constructors");
    ClapTrap bot1("ClapOne");
    ClapTrap bot2(bot1); // Copy constructor
    ClapTrap bot3("ClapThree");
    bot3 = bot1; // Copy assignment operator
    
    printSection("Testing Attack Function");
    bot1.attack("Enemy");
    bot1.attack("Enemy"); // Should reduce energy points
    
    printSection("Testing Attack with 0 Attack Damage");
    ClapTrap bot4("ClapZero");
    bot4.attack("Enemy"); // Should display no damage
    
	printSection("Testing Repairing");
	bot1.beRepaired(3);
	bot1.beRepaired(10); // Should cap at max hit points

    printSection("Testing Taking Damage");
    bot1.takeDamage(5);
    bot1.takeDamage(150); // Should drop to 0 hit points
    bot1.takeDamage(2); // Should not take damage (already dead)
    
    printSection("Testing Repairing when Dead");
    bot1.beRepaired(5); // Should fail because bot2 is dead
    
    printSection("Testing Destructor");
    return 0; // Destructors called automatically here
}
