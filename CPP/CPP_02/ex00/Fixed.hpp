#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
	Fixed();                 // Default constructor
	Fixed(const Fixed &src); // Copy constructor
	~Fixed();                // Destructor

	Fixed &operator=(const Fixed &rhs); // Copy assignment operator

	int getRawBits() const;

	void setRawBits(int const raw);

private:
	int value;
	static const int fractionalBits = 8;
};

#endif
