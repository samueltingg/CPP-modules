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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


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
		ShrubberyCreationForm form1("home");
		ShrubberyCreationForm form2(form1); // Copy constructor
		ShrubberyCreationForm form3("school");
		form3 = form1; // Copy assignment operator
	}

	{
		printSection("Testing Shrubbery's execute");

		std::cout << "Test Case: Normal" << std::endl;
		try {

			ShrubberyCreationForm form("home");
			Bureaucrat bureaucrat("bob", 137);
			bureaucrat.signForm(form);
			form.execute(bureaucrat);
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		try {
			std::cout << "\nTest Case: Form Not Signed" << std::endl;
			ShrubberyCreationForm form("home");
			Bureaucrat bureaucrat("bob", 137);
			// bureaucrat.signForm(form);
			form.execute(bureaucrat);
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		try {
			std::cout << "\nTest Case: Bureaucrat grade too low" << std::endl;
			ShrubberyCreationForm form("home");
			Bureaucrat bureaucrat("bob", 138);
			bureaucrat.signForm(form);
			form.execute(bureaucrat);
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	{
		printSection("Testing Robotomy's execute");

		std::cout << "Test Case: Normal" << std::endl;
		try {

			RobotomyRequestForm form("home");
			Bureaucrat bureaucrat("bob", 45);
			bureaucrat.signForm(form);
			form.execute(bureaucrat);
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		try {
			std::cout << "\nTest Case: Form Not Signed" << std::endl;
			RobotomyRequestForm form("home");
			Bureaucrat bureaucrat("bob", 45);
			// bureaucrat.signForm(form);
			form.execute(bureaucrat);
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		try {
			std::cout << "\nTest Case: Bureaucrat grade too low" << std::endl;
			RobotomyRequestForm form("home");
			Bureaucrat bureaucrat("bob", 46);
			bureaucrat.signForm(form);
			form.execute(bureaucrat);
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	{
		printSection("Testing PresidentialPardon's execute");

		std::cout << "Test Case: Normal" << std::endl;
		try {

			PresidentialPardonForm form("home");
			Bureaucrat bureaucrat("bob", 5);
			bureaucrat.signForm(form);
			form.execute(bureaucrat);
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		try {
			std::cout << "\nTest Case: Form Not Signed" << std::endl;
			PresidentialPardonForm form("home");
			Bureaucrat bureaucrat("bob", 5);
			// bureaucrat.signForm(form);
			form.execute(bureaucrat);
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		try {
			std::cout << "\nTest Case: Bureaucrat grade too low" << std::endl;
			PresidentialPardonForm form("home");
			Bureaucrat bureaucrat("bob", 6);
			bureaucrat.signForm(form);
			form.execute(bureaucrat);
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	{
		printSection("Testing Bureaucrat's executeForm");

		std::cout << "Test: Bureaucrat can execute all Forms" << std::endl;
		try {

			ShrubberyCreationForm shrubForm("home");
			RobotomyRequestForm robotForm("home");
			PresidentialPardonForm preForm("home");
			Bureaucrat bureaucrat("bob", 5);
			bureaucrat.signForm(shrubForm);
			bureaucrat.signForm(robotForm);
			bureaucrat.signForm(preForm);

			std::cout << std::endl;
			bureaucrat.executeForm(shrubForm);

			std::cout << std::endl;
			bureaucrat.executeForm(robotForm);

			std::cout << std::endl;
			bureaucrat.executeForm(preForm);

		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		std::cout << "Test Case: Normal" << std::endl;
		try {

			PresidentialPardonForm form("home");
			Bureaucrat bureaucrat("bob", 5);
			bureaucrat.signForm(form);
			// form.execute(bureaucrat);
			bureaucrat.executeForm(form);
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		try {
			std::cout << "\nTest Case: Form Not Signed" << std::endl;
			PresidentialPardonForm form("home");
			Bureaucrat bureaucrat("bob", 5);
			// bureaucrat.signForm(form);
			bureaucrat.executeForm(form);

		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

		try {
			std::cout << "\nTest Case: Bureaucrat grade too low" << std::endl;
			PresidentialPardonForm form("home");
			Bureaucrat bureaucrat("bob", 6);
			bureaucrat.signForm(form);
			bureaucrat.executeForm(form);
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	return (0);
}
