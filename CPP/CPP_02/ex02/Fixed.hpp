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

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed& operator++(); // Pre-increment
	Fixed operator++(int); // Post-increment
	Fixed& operator--(); // Pre-decrement
	Fixed operator--(int); // Post-decrement

	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);

private:
	int rawBits;
	static const int fractionalBits = 8;
};

#endif
