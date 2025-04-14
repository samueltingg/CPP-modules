/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:15:18 by sting             #+#    #+#             */
/*   Updated: 2025/04/14 17:01:53 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

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
		printSection("Test: Instantiating Bureaucrat with Invalid grade");
		try {
			Bureaucrat bureaucrat1("bob", 0);
		}
		catch (const std::exception &e) {
			std::cerr << "error: " << e.what() << std::endl;
		}

		try {
			Bureaucrat bureaucrat2("john", 151);
		}
		catch (const std::exception &e) {
			std::cerr << "error: " << e.what() << std::endl;
		}

		
	}

	return (0);
}
