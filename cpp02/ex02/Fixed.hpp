/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:13:57 by sting             #+#    #+#             */
/*   Updated: 2025/04/02 15:13:58 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <fstream>
#define FIXED_SCALE (1 << 8) // 2^8 = 256

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define GREY    "\033[90m"

class Fixed {
public:
	//Default Constructor
	Fixed();

	Fixed(const int intNum);
	Fixed(const float floatNum);
	
	// Copy Constructor
	Fixed(const Fixed& other);

	// Copy Assignment Operator Overload
	Fixed& operator=(const Fixed& other);

	// Destructor
	~Fixed();

	int		getRawBits() const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	// Comparison Operators
	bool operator>(const Fixed& fixedPointNum) const;
	bool operator<(const Fixed& fixedPointNum) const;
	bool operator>=(const Fixed& fixedPointNum) const;
	bool operator<=(const Fixed& fixedPointNum) const;
	bool operator==(const Fixed& fixedPointNum) const;
	bool operator!=(const Fixed& fixedPointNum) const;

	// Arithmetic Operators
	Fixed operator+(const Fixed& fixedPointNum) const;
	Fixed operator-(const Fixed& fixedPointNum) const;
	Fixed operator*(const Fixed& fixedPointNum) const;
	Fixed operator/(const Fixed& fixedPointNum) const;

	// Increment/Decrement Operators
	Fixed& operator++();
	Fixed  operator++(int); // the unnamed param "int" is just to indicate for "post-increment"
	Fixed& operator--();
	Fixed  operator--(int); // the unnamed param "int" is just to indicate for "post-decrement"

	static Fixed& min(Fixed& num1, Fixed& num2);
	static const Fixed& min(const Fixed& num1, const Fixed& num2);
	static Fixed& max(Fixed& num1, Fixed& num2);
	static const Fixed& max(const Fixed& num1, const Fixed& num2);


private:
	int	_rawValue; // integer representation of the number in a fixed-point format

	static const int	num_frac_bits = 8; // decimal 
};


std::ostream& operator<<( std::ostream & os, const Fixed& fixedPointNum );

#endif
