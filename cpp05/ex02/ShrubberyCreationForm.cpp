/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:24:03 by sting             #+#    #+#             */
/*   Updated: 2025/04/15 17:26:00 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

#define RESET "\033[0m"
#define GREY "\033[90m"


ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << GREY << "ShrubberyCreationForm:: Constructor Called (target: " << _target << ")" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm("ShrubberyCreationForm", 145, 137), _target(other._target)
{
	std::cout << GREY << "ShrubberyCreationForm:: Copy Constructor Called" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << GREY << "ShrubberyCreationForm:: Copy Assignment Operator Called" << RESET << std::endl;
	
	if (this == &other)
		return *this;

	// const attributes can't be copies
	this->_target = other._target;

	return *this;

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << GREY << "ShrubberyCreationForm:: Destructor Called (target: " << _target << ")" << RESET << std::endl;
}

void writeFile(const std::string& fileName, const std::string& content) {
    std::ofstream ofs(fileName.c_str());
    if (!ofs)
    	throw ShrubberyCreationForm::ErrorWritingToFile();        
    ofs << content;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned() )
		throw ShrubberyCreationForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw ShrubberyCreationForm::GradeTooLowException();
	
	std::string fileName = _target + "_shrubbery";
	std::cout << "File: \"" << fileName << "\" with AsciiTree created." << std::endl;
    std::string asciiTree = 
        "        /\\\n"
        "       /**\\\n"
        "      /****\\\n"
        "     /******\\\n"
        "    /********\\\n"
        "   /**********\\\n"
        "       ||\n"
        "       ||\n";
	writeFile(fileName, asciiTree);
}

