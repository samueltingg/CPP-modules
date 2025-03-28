#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _rawValue(0) 
{
	std::cout << "Default constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawValue);
} 

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawValue = raw;
} 

