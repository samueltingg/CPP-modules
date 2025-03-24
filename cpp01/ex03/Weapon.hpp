/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:43:06 by sting             #+#    #+#             */
/*   Updated: 2025/03/24 16:20:37 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
public:
	Weapon( const std::string type ) : _type(type) {};
	~Weapon() {};
	const std::string&	getType( void ) const;
	void				setType( const std::string newType );

private:
	std::string _type;
};

#endif
