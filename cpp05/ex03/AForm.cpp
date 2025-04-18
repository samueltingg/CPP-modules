/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:06:11 by sting             #+#    #+#             */
/*   Updated: 2025/04/15 16:24:23 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

#define RESET "\033[0m"
#define GREY "\033[90m"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << GREY << "AForm:: Constructor Called (name: " << _name << ")" << RESET << std::endl;
	
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();

}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << GREY << "AForm:: Copy Constructor Called" << RESET << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << GREY << "AForm:: Copy Assignment Operator Called" << RESET << std::endl;
	
	if (this == &other)
		return *this;

	// const attributes can't be copies
	this->_isSigned = other._isSigned;

	return *this;

}

AForm::~AForm()
{
	std::cout << GREY << "AForm:: Destructor Called (name: " << _name << ")" << RESET << std::endl;
}
	

std::string AForm::getName() const
{
	return _name;
}

bool	AForm::getIsSigned() const
{
	return _isSigned;
}

int		AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int		AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream & operator<<( std::ostream & o, AForm const & bureaucrat )
{
	std::cout << "Name: " << bureaucrat.getName() << std::endl
			<< "Is Signed?: " << bureaucrat.getIsSigned() << std::endl
			<< "Grade To Sign: " << bureaucrat.getGradeToSign() << std::endl
			<< "Grade To Execute: " << bureaucrat.getGradeToExecute() << std::endl;

	return o;
}

