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
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm:: Constructor Called (target: " << _target << ")" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm("ShrubberyCreationForm", 145, 137), _target(other._target)
{
	std::cout << "ShrubberyCreationForm:: Copy Constructor Called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm:: Copy Assignment Operator Called" << std::endl;
	
	if (this == &other)
		return *this;

	// const attributes can't be copies
	this->_target = other._target;

	return *this;

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm:: Destructor Called (target: " << _target << ")" << std::endl;
}

void writeFile(const std::string& fileName, const std::string& content) {
    std::ofstream ofs(fileName.c_str());
    if (!ofs)
    	throw ShrubberyCreationForm::ErrorWritingToFile();        
    ofs << content;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::string asciiTree = 
        "        /\\\n"
        "       /**\\\n"
        "      /****\\\n"
        "     /******\\\n"
        "    /********\\\n"
        "   /**********\\\n"
        "       ||\n"
        "       ||\n";

	writeFile(_target + "_shrubbery", asciiTree);
}

