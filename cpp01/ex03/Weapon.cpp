/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:49:20 by sting             #+#    #+#             */
/*   Updated: 2025/03/24 16:20:37 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

const std::string&	Weapon::getType( void ) const {
	return (_type);
}

void Weapon::setType( const std::string newType ) {
	_type = newType;
}

