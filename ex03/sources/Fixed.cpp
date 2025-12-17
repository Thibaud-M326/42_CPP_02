#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() 
: 
	_fixedPoint(0)
{}

Fixed::Fixed(const int toFixed)
:
	_fixedPoint(toFixed << _fracBits)
{}

Fixed::Fixed( const float toFixed ) 
:
	_fixedPoint(static_cast<int>(roundf(toFixed * (1 << _fracBits))))
{}

Fixed::Fixed(const Fixed &copy) 
:
	_fixedPoint(copy._fixedPoint)
{}

Fixed& Fixed::operator=(const Fixed &other) 
{
	if (this == &other)
		return (*this);
	_fixedPoint = other._fixedPoint;
	return (*this);
}

Fixed::~Fixed()
{}

int	Fixed::toInt() const
{
	int toInt;

	toInt = _fixedPoint >> _fracBits;
	return (toInt);
}

float	Fixed::toFloat( void ) const
{
	float toFloat;

	toFloat = static_cast<float>(_fixedPoint) / (1 << _fracBits);
	return (toFloat);
}

int Fixed::getRawBits( void ) const
{
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPoint = raw;		
}

int		Fixed::operator>(const Fixed &f) const
{
	int a;
	int b;

	a = this->getRawBits();
	b = f.getRawBits();
	return (a > b);
}

int		Fixed::operator<(const Fixed &f) const
{
	int a;
	int b;

	a = this->getRawBits();
	b = f.getRawBits();
	return (a < b);
}

int		Fixed::operator>=(const Fixed &f) const
{
	int a;
	int b;

	a = this->getRawBits();
	b = f.getRawBits();
	return (a >= b);
}

int		Fixed::operator<=(const Fixed &f) const
{
	int a;
	int b;

	a = this->getRawBits();
	b = f.getRawBits();
	return (a <= b);
}

int		Fixed::operator==(const Fixed &f) const
{
	int a;
	int b;

	a = this->getRawBits();
	b = f.getRawBits();
	return (a == b);
}

int		Fixed::operator!=(const Fixed &f) const
{
	int a;
	int b;

	a = this->getRawBits();
	b = f.getRawBits();
	return (a != b);
}

Fixed	Fixed::operator+(const Fixed &f) const
{
	float a = this->toFloat();
	float b = f.toFloat();

	return (Fixed((a + b)));
} 

Fixed	Fixed::operator-(const Fixed &f) const
{
	float a = this->toFloat();
	float b = f.toFloat();

	return (Fixed((a - b)));
} 

Fixed	Fixed::operator*(const Fixed &f) const
{
	float a = this->toFloat();
	float b = f.toFloat();

	return (Fixed((a * b)));
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	float a = this->toFloat();
	float b = f.toFloat();

	return (Fixed((a / b)));
} 

Fixed&	Fixed::operator++()
{
	++_fixedPoint;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++_fixedPoint;
	return (temp);
}

Fixed&	Fixed::operator--()
{
	--_fixedPoint;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--_fixedPoint;
	return (temp);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return (stream);	
}