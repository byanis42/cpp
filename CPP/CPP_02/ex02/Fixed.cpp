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

bool Fixed::operator>(const Fixed &other) const {
	return rawBits > other.rawBits;
}

bool Fixed::operator<(const Fixed &other) const {
	return rawBits < other.rawBits;
}

bool Fixed::operator>=(const Fixed &other) const {
	return rawBits >= other.rawBits;
}

bool Fixed::operator<=(const Fixed &other) const {
	return rawBits <= other.rawBits;
}

bool Fixed::operator==(const Fixed &other) const {
	return rawBits == other.rawBits;
}

bool Fixed::operator!=(const Fixed &other) const {
	return rawBits != other.rawBits;
}

Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	if (other.rawBits == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		exit(1);
	}
	return Fixed(toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
	rawBits++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	rawBits++;
	return temp;
}

Fixed& Fixed::operator--() {
	rawBits--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	rawBits--;
	return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}
