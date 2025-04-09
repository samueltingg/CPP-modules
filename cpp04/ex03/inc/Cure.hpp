/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:39:39 by sting             #+#    #+#             */
/*   Updated: 2025/04/09 17:55:08 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
	// Contructor
	Cure();	
	// Copy Constructor
	Cure(const Cure& other);
	// Copy Assignment Operator
	Cure& operator=(const Cure& other);	
	// Destructor
	~Cure();
	
	Cure* clone() const;
	void use(ICharacter& target);

};

#endif

