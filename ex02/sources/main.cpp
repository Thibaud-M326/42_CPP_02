#include "../includes/Fixed.hpp"
#include <iostream>

int main() 
{
	Fixed a( 5.5f );
	Fixed b( 6 );

	std::cout << "comparison operators :" << std::endl;

	if (a > b)
		std::cout << a << " > " << b << " == true" << std::endl;
	else
		std::cout << a << " > " << b << " == false" << std::endl;
	std::cout << std::endl;

	if (a < b)
		std::cout << a << " < " << b << " == true" << std::endl;
	else
		std::cout << a << " < " << b << " == false" << std::endl;
	std::cout << std::endl;

	if (a <= b)
		std::cout << a << " <= " << b << " == true" << std::endl;
	else
		std::cout << a << " <= " << b << " == false" << std::endl;
	std::cout << std::endl;

	if (a >= b)
		std::cout << a << " >= " << b << " == true" << std::endl;
	else
		std::cout << a << " >= " << b << " == false" << std::endl;
	std::cout << std::endl;

	if (a == b)
		std::cout << a << " == " << b << " == true" << std::endl;
	else
		std::cout << a << " == " << b << " == false" << std::endl;
	std::cout << std::endl;

	if (a != b)
		std::cout << a << " != " << b << " == true" << std::endl;
	else
		std::cout << a << " != " << b << " == false" << std::endl;
	std::cout << std::endl;

	std::cout << "arithmetic operators :" << std::endl;

	//-----------//
	Fixed c( 10.5f );
	Fixed d( 2 );

	std::cout << c << " + " << d << " = " << c + d << std::endl;

	std::cout << c << " - " << d << " = " << c - d << std::endl;

	std::cout << c << " * " << d << " = " << c * d << std::endl;

	std::cout << c << " / " << d << " = " << c / d << std::endl;
	std::cout << std::endl;

	//-----------//
	std::cout << "increment/decrement & min/max operations :" << std::endl;
	Fixed z;
	Fixed const x( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << z << std::endl;
	std::cout << ++z << std::endl;
	std::cout << z << std::endl;
	std::cout << z++ << std::endl;
	std::cout << z << std::endl;
	std::cout << x << std::endl;
	std::cout << Fixed::max( z, x ) << std::endl;

	return 0;
}
