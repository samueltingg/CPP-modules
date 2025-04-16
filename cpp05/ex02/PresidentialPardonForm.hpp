/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:23:52 by sting             #+#    #+#             */
/*   Updated: 2025/04/15 15:23:53 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDON_FORM_HPP
#define PRESIDENTIALPARDON_FORM_HPP

#include "AForm.hpp" 

class PresidentialPardonForm : public AForm {
public:
	// Constructor
	PresidentialPardonForm(std::string target);
	// Copy Constructor
	PresidentialPardonForm(const PresidentialPardonForm& other);
	// Copy Assignment Operator
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	// Destructor
	~PresidentialPardonForm();

	void	execute(Bureaucrat const & executor) const;

private:
	std::string	_target;
};

#endif
