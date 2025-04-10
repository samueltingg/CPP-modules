/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:06:20 by sting             #+#    #+#             */
/*   Updated: 2025/04/10 11:26:05 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE
#define MATERIASOURCE

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:

	// Contructor
	MateriaSource();	
	// Copy Constructor
	MateriaSource(const MateriaSource& other);
	// Copy Assignment Operator
	MateriaSource& operator=(const MateriaSource& other);	
	// Destructor
	~MateriaSource();

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
private:
	static const int _maxMateriaCount = 4;
	AMateria	*_inventory[_maxMateriaCount];
};

#endif
