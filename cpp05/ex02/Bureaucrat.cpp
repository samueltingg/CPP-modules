/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:33:56 by sting             #+#    #+#             */
/*   Updated: 2025/04/14 17:43:24 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

#define RESET "\033[0m"
#define GREY "\033[90m"

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade)
{
	std::cout << GREY << "Bureaucrat:: Constructor Called (name: " << _name << ")" << RESET << std::endl;

	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();

}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade)
{
	std::cout << GREY << "Bureaucrat:: Copy Constructor Called" << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << GREY << "Bureaucrat:: Copy Assignment Operator Called" << RESET << std::endl;
	
	if (this == &other)
		return *this;
	// this->_name = other._name;
	// ^ cannot copy '_name' as it is 'const'
	this->_grade = other._grade;

	return *this;

}

Bureaucrat::~Bureaucrat()
{
	std::cout << GREY << "Bureaucrat:: Destructor Called (name: " << _name << ")" << RESET << std::endl;

}
	

std::string Bureaucrat::getName() const
{
	return _name;
}

int			Bureaucrat::getGrade() const
{
	return _grade;
}

void		Bureaucrat::increment()
{
	if (_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
		return ;
	}
	_grade--;
}

void		Bureaucrat::decrement()
{
	if (_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
	_grade++;
}

void	Bureaucrat::signForm(AForm& form)
{
	try {
		form.beSigned(*this);
	}
	catch (const std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << _name << " signed " << form.getName() << std::endl;  
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}


std::ostream & operator<<( std::ostream & o, Bureaucrat const & bureaucrat )
{
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();

	return o;
}

