/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestFormForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:23:49 by sting             #+#    #+#             */
/*   Updated: 2025/04/15 15:23:50 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

#define RESET "\033[0m"
#define GREY "\033[90m"


RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << GREY << "RobotomyRequestForm:: Constructor Called (target: " << _target << ")" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm("RobotomyRequestForm", 72, 45), _target(other._target)
{
	std::cout << GREY << "RobotomyRequestForm:: Copy Constructor Called" << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << GREY << "RobotomyRequestForm:: Copy Assignment Operator Called" << RESET << std::endl;
	
	if (this == &other)
		return *this;

	// const attributes can't be copies
	this->_target = other._target;

	return *this;

}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << GREY << "RobotomyRequestForm:: Destructor Called (target: " << _target << ")" << RESET << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned() )
		throw RobotomyRequestForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw RobotomyRequestForm::GradeTooLowException();
	
}

