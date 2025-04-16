/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:59:34 by sting             #+#    #+#             */
/*   Updated: 2025/04/16 15:32:48 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

struct formType {
	std::string formName;
	AForm* (*funcPtr)(std::string);	
}; 

class Intern {
public:
	// Constructor
	Intern();
	// Copy Constructor
	Intern(const Intern& other);
	// Copy Assignment Operator
	Intern& operator=(const Intern& other);
	// Destructor
	~Intern();

	AForm* makeForm(std::string name, std::string target);
};

#endif

