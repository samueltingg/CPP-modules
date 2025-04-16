/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:23:54 by sting             #+#    #+#             */
/*   Updated: 2025/04/15 15:23:56 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define RESET "\033[0m"
#define GREY "\033[90m"


PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << GREY << "PresidentialPardonForm:: Constructor Called (target: " << _target << ")" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm("PresidentialPardonForm", 25, 5), _target(other._target)
{
	std::cout << GREY << "PresidentialPardonForm:: Copy Constructor Called" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << GREY << "PresidentialPardonForm:: Copy Assignment Operator Called" << RESET << std::endl;
	
	if (this == &other)
		return *this;

	// const attributes can't be copies
	this->_target = other._target;

	return *this;

}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << GREY << "PresidentialPardonForm:: Destructor Called (target: " << _target << ")" << RESET << std::endl;
}

/*
`srand` sets a seed(starting point) for the random number generator used by `rand()` function

using clock() as seed creates more randomness

*/
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned() )
		throw PresidentialPardonForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw PresidentialPardonForm::GradeTooLowException();
	
	std::cout << "Target: "<< _target << ", has been pardoned by Zaphod Beeblebrox." << std::endl;
}

