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
#include <exception>
#include <limits>

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
	T& operator[](size_t i);
	const T& operator[](size_t i) const;


	// custom exception inheriting from 'std::exception'?
	class IndexOutOfBoundsException : public std::exception {
	public: 
		// 'throw()' specifies that func won't throw any exceptions 
        const char* what() const throw() {
            return "Index out of bounds";
        }

	};
	
	size_t size() const;

private:
	T	*_arr;
	size_t _size;
};


template <typename T>
Array<T>::Array() 
	: _arr(new T[0]), _size(0)
{
	std::cout << "Array:: Constructor Called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) 
	: _arr(new T[n]), _size(n) 
{
	std::cout << "Array:: Unsigned Int Constructor Called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other)
	: _arr(new T[other._size]), _size(other._size) 
{
	std::cout << "Array:: Copy Constructor Called" << std::endl;
	
	for (size_t i = 0; i < other._size; i++) {
		this->_arr[i] = other._arr[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	std::cout << "Array:: Copy Assignment Operator Called" << std::endl;
	
	if (this == &other)
		return *this;

	T *newArr = new T[other._size];
	for (size_t i = 0; i < other._size; i++) {
		newArr[i] = other._arr[i];
	}
	delete[] this->_arr;
	_arr = newArr;
	_size = other._size;

	return *this;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array:: Destructor Called" << std::endl;
	delete[] _arr;
}

template <typename T>
T&	Array<T>::operator[](size_t i)
{
	if (i >= _size)
		throw Array::IndexOutOfBoundsException();
	return _arr[i];
}

template <typename T>
const T&	Array<T>::operator[](size_t i) const 
{
	if (i >= _size)
		throw Array::IndexOutOfBoundsException();
	return _arr[i];
}

template <typename T>
size_t Array<T>::size() const
{
	return _size;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
{
	size_t arrSize = arr.size();

	for (size_t i = 0; i < arrSize; i++) {
		os << i << ": " << arr[i] << '\n';
	}
	return os;
}

#endif
