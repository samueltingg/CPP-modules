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

	{
		printSection("Dog: Test if copies are Deep copies");
		Dog dog1;
		Dog dog2 = dog1;

		std::cout << "dog1's brain address: " << dog1.getBrainAddress() << std::endl; 
		std::cout << "dog2's brain address: " << dog2.getBrainAddress() << std::endl; 

	}

	{
		printSection("Cat: Test if copies are Deep copies");
		Cat cat1;
		Cat cat2 = cat1;

		std::cout << "cat1's brain address: " << cat1.getBrainAddress() << std::endl; 
		std::cout << "cat2's brain address: " << cat2.getBrainAddress() << std::endl; 

	}

	{
		printSection("Test: Array of 'Animal' objects");
	   	int arrSize = 6;
		Animal *arr[arrSize];

		for (int i = 0; i < arrSize; ++i) {
			if (i % 2 == 0) // if even
				arr[i] = new Dog();
			else 
				arr[i] = new Cat();
		}

		// Check if arr is filled with cats & dogs evenly
		std::cout << "Animal Array is filled evenly with Dogs & Cats: " << std::endl;
		for (int i = 0; i < arrSize; ++i) {
			std::cout << arr[i]->getType() << std::endl;
		}


		// free arr
		for (int i = 0; i < arrSize; ++i) {
			delete arr[i];		
		}

	}


	return (0);
}
