/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:05:18 by sting             #+#    #+#             */
/*   Updated: 2025/03/21 09:09:41 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>


class Zombie {
public:

	Zombie(void);

	~Zombie(void);
	void	setName(std::string name);
	void 	annouce (void);

private:
	std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
