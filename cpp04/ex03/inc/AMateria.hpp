/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:49:48 by sting             #+#    #+#             */
/*   Updated: 2025/04/09 17:18:34 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter; // Forward declaration to prevent 'Circular Dependency'

class AMateria {
public:
	// Contructor
	AMateria(std::string const & type);	
	// Copy Constructor
	AMateria(const AMateria& other);
	// Copy Assignment Operator
	AMateria& operator=(const AMateria& other);	
	// Destructor
	virtual ~AMateria();

	std::string const & getType() const; //Returns the materia type
	
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	std::string type;

};

#endif  
