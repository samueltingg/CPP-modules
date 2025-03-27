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
	int	_value;
	static const int	num_frac_bits = 8;
};

#endif
