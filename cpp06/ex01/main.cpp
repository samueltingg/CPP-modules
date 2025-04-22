/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:55:13 by sting             #+#    #+#             */
/*   Updated: 2025/04/22 19:02:14 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data obj;
	Data *dataPtr;

	obj.value = 42;
	std::cout << "Data object value: " << obj.value << "\n";
	dataPtr = Serializer::deserialize(Serializer::serialize(&obj));

	if (dataPtr == &obj) {
		std::cout << "return value of 'deserialize' is EQUAL to address of Data Object\n";
		std::cout << "Data object value (From deserialize): " << dataPtr->value << "\n";
	}
	else
		std::cout << "return value of 'deserialize' is NOT EQUAL to address of Data Object\n";

}
