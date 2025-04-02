/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:13:22 by sting             #+#    #+#             */
/*   Updated: 2025/04/02 15:13:31 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <fstream>
#define FIXED_SCALE (1 << 8) // 2^8 = 256

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

private:
	int	_rawValue; // integer representation of the number in a fixed-point format

	static const int	num_frac_bits = 8; // decimal 
};


std::ostream & operator<<( std::ostream & os, const Fixed& fixedPointNum );

#endif
