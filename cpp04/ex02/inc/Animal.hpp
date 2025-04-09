/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:32:07 by sting             #+#    #+#             */
/*   Updated: 2025/04/08 11:50:35 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
public:

	// Constructor
	Animal();
	// Copy Constructor
	Animal(const Animal& other);
	// Copy Assignment Operator
	Animal& operator=(const Animal& other);
	// Destructor
	virtual ~Animal();
	
	std::string getType() const;
	virtual void makeSound() const = 0;

protected:
	std::string type;
};


#endif
