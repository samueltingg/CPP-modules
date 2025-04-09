/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:37:40 by sting             #+#    #+#             */
/*   Updated: 2025/04/08 11:44:20 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:

	// Constructor
	Dog();
	// Copy Constructor
	Dog(const Dog& other);
	// Copy Assignment Operator
	Dog& operator=(const Dog& other);
	// Destructor
	~Dog();

	void makeSound() const; 
	const Brain *getBrainAddress() const;

private:
	Brain	*_brain;

};


#endif
