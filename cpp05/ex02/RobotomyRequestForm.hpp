/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:23:46 by sting             #+#    #+#             */
/*   Updated: 2025/04/15 15:23:48 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp" 

class RobotomyRequestForm : public AForm {
public:
	// Constructor
	RobotomyRequestForm(std::string target);
	// Copy Constructor
	RobotomyRequestForm(const RobotomyRequestForm& other);
	// Copy Assignment Operator
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	// Destructor
	~RobotomyRequestForm();

	void	execute(Bureaucrat const & executor) const;

private:
	std::string	_target;
};

#endif
