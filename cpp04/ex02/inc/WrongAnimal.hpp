/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:05:56 by sting             #+#    #+#             */
/*   Updated: 2025/04/08 17:32:59 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
public:

	// Constructor
	WrongAnimal();
	// Copy Constructor
	WrongAnimal(const WrongAnimal& other);
	// Copy Assignment Operator
	WrongAnimal& operator=(const WrongAnimal& other);
	// Destructor
	virtual ~WrongAnimal();
	
	std::string getType() const;
	void makeSound() const; // Not set as "virtual"

protected:
	std::string type;
};


#endif
