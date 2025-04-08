/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:39:17 by sting             #+#    #+#             */
/*   Updated: 2025/04/08 11:44:15 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:

	// Constructor
	Cat();
	// Copy Constructor
	Cat(const Cat& other);
	// Copy Assignment Operator
	Cat& operator=(const Cat& other);
	// Destructor
	~Cat();

	void makeSound() const;
private:
	Brain	*_brain;
};


#endif
