/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:05:35 by sting             #+#    #+#             */
/*   Updated: 2025/04/08 17:31:31 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal {
public:

	// Constructor
	WrongCat();
	// Copy Constructor
	WrongCat(const WrongCat& other);
	// Copy Assignment Operator
	WrongCat& operator=(const WrongCat& other);
	// Destructor
	~WrongCat();

	void makeSound() const;
};


#endif
