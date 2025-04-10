/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:04:56 by sting             #+#    #+#             */
/*   Updated: 2025/04/10 11:06:31 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter {

public:
	// Contructor
	Character(std::string name);	
	// Copy Constructor
	Character(const Character& other);
	// Copy Assignment Operator
	Character& operator=(const Character& other);	
	// Destructor
	~Character();

	std::string const & getName() const;

	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	std::string _name;
	static const int _maxMateriaCount = 4;
	AMateria	*_inventory[_maxMateriaCount];
};

#endif
