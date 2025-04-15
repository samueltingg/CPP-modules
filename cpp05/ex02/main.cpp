/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:15:18 by sting             #+#    #+#             */
/*   Updated: 2025/04/15 17:30:00 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"


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
		printSection("Testing 'Bureaucrat' Constructors");
		Bureaucrat bureaucrat1("bob", 1);
		Bureaucrat bureaucrat2(bureaucrat1); // Copy constructor
		Bureaucrat bureaucrat3("john", 150);
		bureaucrat3 = bureaucrat1; // Copy assignment operator
	}

	{
		printSection("Test: Bureaucrat'<<' overload");
		Bureaucrat bureaucrat1("bob", 1);
		std::cout << bureaucrat1 << std::endl; 
	}


	{
		printSection("Test: Instantiating Bureaucrat with Invalid grade");
		try {
			Bureaucrat bureaucrat1("bob", 0); // too high
		}
		catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		try {
			Bureaucrat bureaucrat2("john", 151); // too low
		}
		catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		
	}

	{
		printSection("test: increment()");

		try {
			Bureaucrat bureaucrat1("bob", 2);

			std::cout << "\nbefore increment: " << std::endl; 
			std::cout << bureaucrat1 << std::endl;
			bureaucrat1.increment();
			std::cout << "after increment: " << std::endl; 
			std::cout << bureaucrat1 << std::endl;
			std::cout << std::endl;

			std::cout << "Attempt to increment to out of range grade: " << std::endl; 
			bureaucrat1.increment();
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

	}

	{
		printSection("test: decrement()");

		try {
			Bureaucrat bureaucrat1("bob", 149);

			std::cout << "\nbefore decrement: " << std::endl; 
			std::cout << bureaucrat1 << std::endl;
			bureaucrat1.decrement();
			std::cout << "after decrement: " << std::endl; 
			std::cout << bureaucrat1 << std::endl;
			std::cout << std::endl;

			std::cout << "Attempt to decrement to out of range grade: " << std::endl; 
			bureaucrat1.decrement();
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	// {
	// 	printSection("Testing 'AForm' Constructors");
	// 	AForm form1("form1", 100, 50);
	// 	AForm form2(form1); // Copy constructor
	// 	AForm form3("form2", 130, 150);
	// 	form3 = form1; // Copy assignment operator
	// }
	
	
	{
		printSection("Testing 'Shrubbery' Constructors");
		ShrubberyCreationForm form1("bob", 1);
		ShrubberyCreationForm form2(form1); // Copy constructor
		ShrubberyCreationForm form3("john", 150);
		form3 = form1; // Copy assignment operator
	}

	// {
	// 	printSection("Test: AForm '<<' overload");
	// 	AForm form1("form1", 100, 50);
	//
	// 	std::cout << "\nInitial attribute values of AForm: " << std::endl; 
	// 	std::cout << form1 << std::endl; 
	// }
	//
	// {
	// 	printSection("Test: Bureaucrat's signForm() + Form's beSigned()");
	// 	Bureaucrat bureaucrat1("bureaucrat1", 100);	
	// 	Bureaucrat bureaucrat2("bureaucrat2", 101);	
	// 	AForm form1("form1", 100, 50);
	//
	// 	std::cout << "\nSuccessful Attempt for " << bureaucrat1.getName() << " to sign " << form1.getName() << ": "<< std::endl;
	// 	bureaucrat1.signForm(form1);
	//
	// 	std::cout << "\nUnsuccessful Attempt for " << bureaucrat2.getName() << " to sign " << form1.getName() << ": "<< std::endl;
	// 	bureaucrat2.signForm(form1);
	// 	std::cout << std::endl;
	//
	// }

	return (0);
}
