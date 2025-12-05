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
	_fixedPoint = static_cast<int>(roundf(toFixed * (1 << _fracBits)));
}

int	Fixed::toInt() const {
	int toInt;

	toInt = _fixedPoint >> _fracBits;
	return (toInt);
}

float	Fixed::toFloat( void ) const {
	float toFloat;

	toFloat = static_cast< float >(_fixedPoint) / (1 << _fracBits);
	return (toFloat);
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPoint = raw;		
}

//private

//overload
std::ostream& operator<< (std::ostream& stream, const Fixed& fixed) {
	stream << fixed.toFloat();
	return (stream);	
}