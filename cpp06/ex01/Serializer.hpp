/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:24:04 by sting             #+#    #+#             */
/*   Updated: 2025/04/22 18:32:30 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <iostream>
#include "Data.hpp"


class Serializer {
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	// Default Constructor
	Serializer();
	// Copy Constructor
	Serializer(const Serializer& other);
	// Copy Assignment Operator
	Serializer& operator=(const Serializer& other);
	// Destructor
	~Serializer();
};

#endif
