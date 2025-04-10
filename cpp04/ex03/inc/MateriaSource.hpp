/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:06:20 by sting             #+#    #+#             */
/*   Updated: 2025/04/10 10:08:00 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE
#define MATERIASOURCE

#include "AMateria.hpp"

class MateriaSource {
public:

	// Contructor
	MateriaSource();	
	// Copy Constructor
	MateriaSource(const MateriaSource& other);
	// Copy Assignment Operator
	MateriaSource& operator=(const MateriaSource& other);	
	// Destructor
	~MateriaSource();

	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};

#endif
