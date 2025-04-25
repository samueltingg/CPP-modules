/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:54:35 by sting             #+#    #+#             */
/*   Updated: 2025/04/23 18:14:45 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>		
#include <limits>
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define GREY "\033[90m"

#define MAX_VAL 5 

void printSection(const std::string &title) {
	std::cout << CYAN << BOLD << "\n=== " << title << " ===" << RESET
		<< std::endl;
}

int main(int, char**)
{
	{

		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];

		std::cout << "size of Array: " << numbers.size() << '\n';
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}


		for (size_t i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		std::cout << "Successfully saved the same value" << std::endl;


		try
		{
			std::cout << "==== Testing index -2 ====\n";
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			std::cout << "==== Testing index MAX_VAL ====\n";
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}

	{
		printSection("Instantiating Empty Array");
		Array<int> numbers;
		std::cout << "size: " << numbers.size() << '\n';
		std::cout << "Empty Array: "<< numbers << "\n\n";
	}
	//SCOPE
	{
		printSection("Testing Copy Constructor & Copy Assignment Operator");
		Array<int> arr1(5);
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			arr1[i] = value;
		}

		Array<int> arr2(arr1);
		Array<int> arr3;
		arr3 = arr1;

		std::cout << "arr1: \n" << arr1; 
		std::cout << "arr2: \n" << arr2; 
		std::cout << "arr3: \n" << arr3; 
	}
}
