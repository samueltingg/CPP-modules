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

/*int main()*/
/*{*/
/*	// Constructors Test*/
/*	ClapTrap clapTrap1("Bob");*/
/*	ClapTrap clapTrap2(clapTrap1);*/
/*	ClapTrap clapTrap3("Steve");*/
/**/
/*	clapTrap3 = clapTrap2;*/
/**/
/*	std::cout << "Name of clapTrap1: " << clapTrap1.getName() << std::endl;*/
/*	std::cout << "Name of clapTrap2: " << clapTrap2.getName() << std::endl;*/
/*	std::cout << "Name of clapTrap3: " << clapTrap3.getName() << std::endl;*/
/*	std::cout << std::endl;*/
/**/
/**/
/*	std::cout << "Values BEFORE attack->" */
/*				<< " hitPoints: " << clapTrap1.getHitPoints()	*/
/*				<< " energyPoints: " << clapTrap2.getHitPoints()*/
/*				<< " attackDamage: " << clapTrap3.getAttackDamage() << std::endl;*/
/*	clapTrap1.attack("another clapTrap");*/
/*	std::cout << "Values AFTER attack->" */
/*				<< " hitPoints: " << clapTrap1.getHitPoints()	*/
/*				<< " energyPoints: " << clapTrap2.getHitPoints()*/
/*				<< " attackDamage: " << clapTrap3.getAttackDamage() << std::endl;*/
/*	std::cout << std::endl;*/
/**/
/*	std::cout << "Values BEFORE takeDamage>" */
/*				<< " hitPoints: " << clapTrap1.getHitPoints()	*/
/*				<< " energyPoints: " << clapTrap2.getHitPoints()*/
/*				<< " attackDamage: " << clapTrap3.getAttackDamage() << std::endl;*/
/*	clapTrap1.takeDamage(5);*/
/*	std::cout << "Values AFTER attack->" */
/*				<< " hitPoints: " << clapTrap1.getHitPoints()	*/
/*				<< " energyPoints: " << clapTrap2.getHitPoints()*/
/*				<< " attackDamage: " << clapTrap3.getAttackDamage() << std::endl;*/
/*	std::cout << std::endl;*/
/**/
/*}*/



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
    
    printSection("Testing Taking Damage");
    bot2.takeDamage(5);
    bot2.takeDamage(6); // Should drop to 0 hit points
    bot2.takeDamage(2); // Should not take damage (already dead)
    
    printSection("Testing Repairing");
    bot3.beRepaired(3);
    bot3.beRepaired(10); // Should cap at max hit points
    
    /*printSection("Testing Repairing with 0 Energy Points");*/
    /*for (int i = 0; i < 10; i++) bot3.attack("Enemy"); // Deplete energy*/
    /*bot3.beRepaired(3); // Should fail due to 0 energy*/
    
    printSection("Testing Repairing when Dead");
    bot2.beRepaired(5); // Should fail because bot2 is dead
    
    printSection("Testing Destructor");
    return 0; // Destructors called automatically here
}
