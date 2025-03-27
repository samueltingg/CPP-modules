#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) 
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		_value = other._value;
	}
	return(*this);
}

Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
}

// int	getRawBits() const 
// {
//
// }
//
// void setRawBits( int const raw )
// {
//
// }

