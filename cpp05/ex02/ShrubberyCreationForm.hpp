/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:24:05 by sting             #+#    #+#             */
/*   Updated: 2025/04/15 17:25:11 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp" 

class ShrubberyCreationForm : public AForm {
public:
	// Constructor
	ShrubberyCreationForm(std::string target);
	// Copy Constructor
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	// Copy Assignment Operator
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	// Destructor
	~ShrubberyCreationForm();

	void	execute(Bureaucrat const & executor) const;

	class ErrorWritingToFile : public std::exception {
	public:
        const char* what() const throw() {
            return "Grade is too low";
        }
	}

private:
	std::string	_target;
};

#endif
