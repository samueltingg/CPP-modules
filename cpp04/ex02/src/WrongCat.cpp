/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:06:10 by sting             #+#    #+#             */
/*   Updated: 2025/04/08 17:31:56 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
	: WrongAnimal() 
{
	std::cout << "WrongCat: Constructor Called" << std::endl;
	WrongAnimal::type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal()
{
	std::cout << "WrongCat: Copy Constructor Called" << std::endl;
	this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat: Copy Assignment Operator Called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor Called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "< Meow Meow Meow >" << std::endl;
}
