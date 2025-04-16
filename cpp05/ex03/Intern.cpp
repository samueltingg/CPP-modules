/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:59:31 by sting             #+#    #+#             */
/*   Updated: 2025/04/16 15:44:33 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RESET "\033[0m"
#define GREY "\033[90m"

Intern::Intern()
{
	std::cout << GREY << "Intern:: Constructor Called" << RESET << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << GREY << "Intern:: Copy Constructor Called" << RESET << std::endl;
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << GREY << "Intern:: Copy Assignment Operator Called" << RESET << std::endl;
	
	if (this == &other)
		return *this;

	return *this;
}

Intern::~Intern()
{
	std::cout << GREY << "Intern:: Destructor Called" << RESET << std::endl;
}
	
AForm	*createShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*createRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm	*createPresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	const formType arr[] = {
		{"shrubbery creation", createShrubberyCreationForm},
		{"robotomy request", createRobotomyRequestForm},
		{"presidential pardon", createPresidentialPardonForm}
	};

	int arrSize = sizeof(arr) / sizeof(arr[0]);
	int i;
	for (i = 0; i < arrSize; ++i) {
		if (arr[i].formName == name)
			break;
	}

	if (i == arrSize) {
		std::cout << "makeForm: formName doesn't exist" << std::endl;
		return NULL;
	}
		
	std::cout << "Intern creates " << arr[i].formName << std::endl;
	return arr[i].funcPtr(target);
}

