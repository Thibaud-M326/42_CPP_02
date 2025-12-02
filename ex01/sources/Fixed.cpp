#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

//public
Fixed::Fixed() : 
	_fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPoint = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_fixedPoint = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int toFixed) {
	_fixedPoint = toFixed << _fracBits;
}

Fixed::Fixed( const float toFixed ) {
	_fixedPoint = roundf(toFixed * (1 << _fracBits));
}

float	Fixed::toFloat( void ) const {
	float toFloat;

	toFloat = _fixedPoint >> _fracBits;
	return (toFloat);
}

int	Fixed::toInt() const {
	int toInt;

	toInt = _fixedPoint >> _fracBits;
	return (toInt);
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPoint = raw;		
}

//private