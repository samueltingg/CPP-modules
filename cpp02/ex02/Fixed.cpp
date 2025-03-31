#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _rawValue(0) 
{
	std::cout << GREY << "Default constructor called" << RESET << std::endl;
} 

Fixed::Fixed(const int intNum)
{
	std::cout << GREY << "Int constructor called" << RESET<< std::endl;   
	_rawValue = intNum << num_frac_bits;
}

Fixed::Fixed(const float floatNum)
{
	std::cout << GREY << "Float constructor called" << RESET<< std::endl;   
	_rawValue = static_cast<int>(roundf(floatNum * FIXED_SCALE)); 
	// use roundf as casting to int directly will truncate decimal part
}


Fixed::Fixed(const Fixed& other) 
{
	std::cout << GREY << "Copy constructor called" << RESET<< std::endl;   
	this->_rawValue = other._rawValue;
} 

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << GREY << "Copy Assignment Operator called" << RESET<< std::endl;   
	if (this != &other) { // Prevent self-assignment
		_rawValue = other._rawValue;
	} 
	return(*this);
} 

Fixed::~Fixed() 
{
	std::cout << GREY << "Destructor called" << RESET<< std::endl;   
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

bool Fixed::operator>(const Fixed& fixedPointNum) const
{
	return (this->_rawValue > fixedPointNum._rawValue);
}
       
bool Fixed::operator<(const Fixed& fixedPointNum) const
{
	return (this->_rawValue < fixedPointNum._rawValue);
}

bool Fixed::operator>=(const Fixed& fixedPointNum) const
{
	return (this->_rawValue >= fixedPointNum._rawValue);
}

bool Fixed::operator<=(const Fixed& fixedPointNum) const
{
	return (this->_rawValue <= fixedPointNum._rawValue);
}

bool Fixed::operator==(const Fixed& fixedPointNum) const
{
	return (this->_rawValue == fixedPointNum._rawValue);
}

bool Fixed::operator!=(const Fixed& fixedPointNum) const
{
	return (this->_rawValue != fixedPointNum._rawValue);
}

// Arithmetic Operators       
Fixed Fixed::operator+(const Fixed& fixedPointNum) const
{
	Fixed newNum;
	newNum._rawValue = this->_rawValue + fixedPointNum._rawValue;
	return (newNum);
}

Fixed Fixed::operator-(const Fixed& fixedPointNum) const
{
	Fixed newNum;
	newNum._rawValue = this->_rawValue - fixedPointNum._rawValue;
	return (newNum);

}

/*
Divide both '_rawValues' by FIXED_SCALE bcuz

multiplying both _rawValues alone will will scale the result by 2 times, since each _rawValue is scaled by 2^8
*/
Fixed Fixed::operator*(const Fixed& fixedPointNum) const
{
	Fixed newNum;
	newNum._rawValue = (this->_rawValue * fixedPointNum._rawValue) / FIXED_SCALE;
	return (newNum);
}

Fixed Fixed::operator/(const Fixed& fixedPointNum) const
{
	Fixed newNum;
	newNum._rawValue = (this->_rawValue / fixedPointNum._rawValue) * FIXED_SCALE;
	return (newNum);
}

/*

SMALLEST POSSIBLE INCREMENT
------------------------------
Since _rawValue is bit shifted right by 8 when converting back to int/float, the smallest possible increment/decrement for _rawValue is 1

Incrementing '_rawValue' by 1 actually increases the actual value by 2^-8
- because when _rawValue is converted back to float/int, we shift all bits to right by 8 

*/

Fixed& Fixed::operator++()
{
	++_rawValue;
	return (*this);	
}

Fixed  Fixed::operator++(int) // the unnamed param "int" is just to indicate for "post-increment"      
{
	Fixed temp = *this;
	++_rawValue;
	return (temp);	
}
Fixed& Fixed::operator--()
{
	--_rawValue;
	return (*this);	

}
Fixed  Fixed::operator--(int) // the unnamed param "int" is just to indicate for "post-decrement"
{
	Fixed temp = *this;
	--_rawValue;
	return (temp);	
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
	return (num1 < num2) ? num1 : num2;
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
	return (num1 < num2) ? num1 : num2;
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
	return (num1 > num2) ? num1 : num2;
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
	return (num1 > num2) ? num1 : num2;
}

std::ostream & operator<<( std::ostream & os, const Fixed& fixedPointNum) 
{
	float floatNum = fixedPointNum.toFloat();

	os << floatNum; // if floatNum has not fractional value (eg. 1.00), it will printed as "1"
	return (os);
}

