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
		printSection("Testing 'MateriaSource' Constructors");
		MateriaSource materiaSourc31;
		MateriaSource materiaSourc32(materiaSourc31); // Copy constructor
		MateriaSource materiaSourc33;
		materiaSourc33 = materiaSourc31; // Copy assignment operator
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

	{
		printSection("Testing Charater's member Functions ");
		std::cout << "---equip()----" << std::endl;

		Character me("me");
		AMateria *ice1 = new Ice();
		AMateria *ice2 = new Ice();
		AMateria *ice3 = new Ice();
		AMateria *ice4 = new Ice();
		AMateria *ice5 = new Ice();
		std::cout << std::endl;

		std::cout << "calling equiping 5 times: " << std::endl;	
		me.equip(ice1);
		me.equip(ice2);
		me.equip(ice3);
		me.equip(ice4);
		me.equip(ice5);
		std::cout << std::endl;

		std::cout << "---unequip()----" << std::endl;
		std::cout << "Inventory Before:" << std::endl;
		for (int i = 0; i < Character::maxMateriaCount; i++) {
			std::cout << "index: " << i << "-> " << me.getMateriaFromInventory(i)->getType() << std::endl;
		}

		std::cout << std::endl;
		me.unequip(2);

		std::cout << "Inventory After:" << std::endl;
		for (int i = 0; i < Character::maxMateriaCount; i++) {
			if (me.getMateriaFromInventory(i))
				std::cout << "index: " << i << "-> " << me.getMateriaFromInventory(i)->getType() << std::endl;
			else
				std::cout << "index: " << i << "-> " << std::endl;

		}
		std::cout << std::endl;

		std::cout << "calling unequip() on non-existent Materia: " << std::endl;
		me.unequip(2);
		std::cout << std::endl;	


		std::cout << "----use()----" << std::endl;
		std::cout << "calling use() on non-existent Materia: " << std::endl;
		me.use(2, me);
		std::cout << std::endl;	

		std::cout << "Destructors:" << std::endl;
		delete ice3;
		delete ice5;
	}
	{
		printSection("Testing Materiasource's member Functions ");
		std::cout << "---learnMateria()----" << std::endl;

		MateriaSource source;
		AMateria *ice1 = new Ice();
		AMateria *ice2 = new Ice();
		AMateria *ice3 = new Ice();
		AMateria *ice4 = new Ice();
		AMateria *ice5 = new Ice();
		std::cout << std::endl;

		std::cout << "calling learn Materia 5 times: " << std::endl;	
		source.learnMateria(ice1);
		source.learnMateria(ice2);
		source.learnMateria(ice3);
		source.learnMateria(ice4);
		source.learnMateria(ice5);
		std::cout << std::endl;


		std::cout << "---createMateria()----" << std::endl;
		std::cout << "createMateria with unknown type" << std::endl;	
		AMateria *ret = source.createMateria("unknown type");
		std::cout << "return value: " << ret << std::endl; 
		std::cout << std::endl;

		delete ice5;


	}


	
	return (0);
}
