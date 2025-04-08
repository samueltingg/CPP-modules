/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:15:18 by sting             #+#    #+#             */
/*   Updated: 2025/04/08 17:39:17 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

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
	printSection("Testing 'Animal' Constructors");
	Animal animal1;
	Animal animal2(animal1); // Copy constructor
	Animal animal3;
	animal3 = animal1; // Copy assignment operator
	}

	{
	printSection("Testing 'Dog' Constructors");
	Dog dog1;
	Dog dog2(dog1); // Copy constructor
	Dog dog3;
	dog3 = dog1; // Copy assignment operator
	}

	{
	printSection("Testing 'Cat' Constructors");
	Cat cat1;
	Cat cat2(cat1); // Copy constructor
	Cat cat3;
	cat3 = cat1; // Copy assignment operator
	}
	
	{
		printSection("Subject PDF tests");
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	{
	printSection("Testing WrongAnimal & WrongCat");
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the animal sound instead of cat!
	meta->makeSound();

	delete meta;
	delete i;
	}

	return (0);
}
