/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:15:18 by sting             #+#    #+#             */
/*   Updated: 2025/04/10 11:08:39 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/AMateria.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/Character.hpp"
#include "../inc/IMateriaSource.hpp"
#include "../inc/MateriaSource.hpp"


#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define GREY "\033[90m"

void printSection(const std::string &title) {
	std::cout << CYAN << BOLD << "\n=== " << title << " ===" << RESET
		<< std::endl;
}

int	main()
{
	{
		printSection("Testing 'Character' Constructors");
		Character character1("bob");
		Character character2(character1); // Copy constructor
		Character character3("John");
		character3 = character1; // Copy assignment operator
	}

	{
		printSection("Testing 'Ice' Constructors");
		Ice ice1;
		Ice ice2(ice1); // Copy constructor
		Ice ice3;
		ice3 = ice1; // Copy assignment operator
	}

	{
		printSection("Testing 'Cure' Constructors");
		Cure cure1;
		Cure cure2(cure1); // Copy constructor
		Cure cure3;
		cure3 = cure1; // Copy assignment operator
	}

	
	{
		printSection("Subject PDF tests");
		IMateriaSource* src = new MateriaSource();
		std::cout << std::endl;

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << std::endl;

		ICharacter* me = new Character("me");
		AMateria* tmp;
		std::cout << std::endl;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		std::cout << std::endl;

		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << std::endl;

		ICharacter* bob = new Character("bob");
		std::cout << std::endl;

		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << std::endl;

		delete bob;
		delete me;
		delete src;
	}

	
	return (0);
}
