/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:06:11 by sting             #+#    #+#             */
/*   Updated: 2025/04/14 18:20:32 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form:: Constructor Called (name: " << _name << ")" << std::endl;
	
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Bureaucrat::GradeTooLowException();

}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form:: Copy Constructor Called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form:: Copy Assignment Operator Called" << std::endl;
	
	if (this == &other)
		return *this;

	// const attributes can't be copies
	this->_isSigned = other._isSigned;

	return *this;

}

Form::~Form()
{
	std::cout << "Form:: Destructor Called (name: " << _name << ")" << std::endl;
}
	

std::string Form::getName() const
{
	return _name;
}

bool	Form::getIsSigned() const
{
	return _isSigned;
}

int		Form::getGradeToSign() const
{
	return _gradeToSign;
}

int		Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream & operator<<( std::ostream & o, Form const & bureaucrat )
{
	std::cout << "Name: " << bureaucrat.getName() << std::endl
			<< "Is Signed?: " << bureaucrat.getIsSigned() << std::endl
			<< "Grade To Sign: " << bureaucrat.getGradeToSign() << std::endl
			<< "Grade To Execute: " << bureaucrat.getGradeToExecute() << std::endl;

	return o;
}

