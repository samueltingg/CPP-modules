/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:11:40 by sting             #+#    #+#             */
/*   Updated: 2025/04/23 18:14:50 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdio.h>
#include <iostream>

template <typename T>
class Array {
public:
	// Default Constructor
	Array();	
	// Unsigned int Constructor
	Array(unsigned int n);
	// Copy Constructor
	Array(const Array& other);	
	// Copy Assignment Operator
	Array& operator=(const Array& other);	
	// Destructor
	~Array();
	//operator[] overload
	T operator[](int i);


	// custom exception inheriting from 'std::exception'?
	
	size_t size() const;

private:
	T	*arr;
};

template <typename T>
Array<T>::Array()
{
	std::cout << "Array:: Constructor Called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Array:: Unsigned Int Constructor Called" << std::endl;
}

template <typename T>
Array::Array(const Array& other)
{
	std::cout << "Array:: Copy Constructor Called" << std::endl;
}

template <typename T>
Array& Array<T>::operator=(const Array& other)
{
	std::cout << "Array:: Copy Assignment Operator Called" << std::endl;
	
	if (this == &other)
		return *this;
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array:: Destructor Called" << std::endl;
}

template <typename T>
T	Array<T>operator[](int i)
{

}


template <typename T>
size_t Array<T>size() const
{

}

#endif
