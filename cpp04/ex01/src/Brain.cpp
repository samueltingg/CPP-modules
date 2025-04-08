/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:57:23 by sting             #+#    #+#             */
/*   Updated: 2025/04/08 18:13:26 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain: Constructor Called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain: Copy Constructor Called" << std::endl;
	for (int i = 0; i < 100; ++i) {
		this->ideas[i] = other.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain: Copy Assignment Operator Called" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; ++i) {
		this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor Called" << std::endl;
}

