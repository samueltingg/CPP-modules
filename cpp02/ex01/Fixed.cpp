/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:13:19 by sting             #+#    #+#             */
/*   Updated: 2025/04/02 15:13:36 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _rawValue(0) 
{
	std::cout << "Default constructor called" << std::endl;
} 

Fixed::Fixed(const int intNum)
{
	std::cout << "Int constructor called" << std::endl;
	_rawValue = intNum << num_frac_bits;
}

Fixed::Fixed(const float floatNum)
{
	std::cout << "Float constructor called" << std::endl;
	_rawValue = static_cast<int>(roundf(floatNum * FIXED_SCALE)); 
	// use roundf as casting to int directly will truncate decimal part
}

Fixed::Fixed(const Fixed& other) 
{
	std::cout << "Copy constructor called" << std::endl;
	this->_rawValue = other._rawValue;
} 

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy Assignment Operator called" << std::endl;
	if (this != &other) { // Prevent self-assignment
		_rawValue = other._rawValue;
	} 
	return(*this);
} 

Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
} 


// returns raw value: actual integer representation of the number in a fixed-point format
int	Fixed::getRawBits() const 
{
	return (_rawValue);
} 

void Fixed::setRawBits( int const raw )
{
	_rawValue = raw;
} 

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>((float)_rawValue / FIXED_SCALE));
	// cannot bit shift as unlike 'int', 'float' aren't stored as raw binary numbers
}

int		Fixed::toInt( void ) const 
{
	return (_rawValue >> num_frac_bits);
}

std::ostream & operator<<( std::ostream & os, const Fixed& fixedPointNum) 
{
	float floatNum = fixedPointNum.toFloat();

	os << floatNum; // if floatNum has not fractional value (eg. 1.00), it will printed as "1"
	return (os);
}

