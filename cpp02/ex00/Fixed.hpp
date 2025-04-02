/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:12:27 by sting             #+#    #+#             */
/*   Updated: 2025/04/02 15:12:28 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
	//Default Constructor
	Fixed();

	// Copy Constructor
	Fixed(const Fixed& other);

	// Copy Assignment Operator Overload
	Fixed& operator=(const Fixed& other);

	// Destructor
	~Fixed();

	int	getRawBits() const;
	void setRawBits( int const raw );
private:
	int	_rawValue;
	static const int	num_frac_bits = 8;
};

#endif
