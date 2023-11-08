#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : rawBits(value << fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : rawBits(roundf(value * (1 << fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : rawBits(other.rawBits) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		rawBits = other.rawBits;
	}
	return *this;
}

float Fixed::toFloat() const {
	return static_cast<float>(rawBits) / (1 << fractionalBits);
}

int Fixed::toInt() const {
	return rawBits >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
