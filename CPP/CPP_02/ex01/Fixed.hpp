#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();

	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);

	float toFloat() const;
	int toInt() const;

	friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

private:
	int rawBits;
	static const int fractionalBits = 8;
};

#endif
