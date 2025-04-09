/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:24:51 by sting             #+#    #+#             */
/*   Updated: 2025/04/09 17:40:04 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
	// Contructor
	Ice();	
	// Copy Constructor
	Ice(const Ice& other);
	// Copy Assignment Operator
	Ice& operator=(const Ice& other);	
	// Destructor
	~Ice();
	
	Ice* clone() const;
	void use(ICharacter& target);

};

#endif

