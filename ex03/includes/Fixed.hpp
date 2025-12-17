#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <limits>

class Fixed {

	public:
		Fixed();
		Fixed( const int toFixed );
		Fixed( const float toFixed );

		Fixed(const Fixed &copy);
		Fixed& operator=(const Fixed &other);

		~Fixed();

		int			toInt( void ) const;
		float		toFloat( void ) const;
		int			getRawBits( void ) const;
		void		setRawBits(int const raw);

		int			operator>(const Fixed &f) const;
		int			operator<(const Fixed &f) const;
		int			operator>=(const Fixed &f) const;
		int			operator<=(const Fixed &f) const;
		int			operator==(const Fixed &f) const;
		int			operator!=(const Fixed &f) const;

		Fixed		operator+(const Fixed &f) const;
		Fixed		operator-(const Fixed &f) const;
		Fixed		operator*(const Fixed &f) const;
		Fixed		operator/(const Fixed &f) const;

		Fixed&		operator++();
		Fixed		operator++(int);
		Fixed&		operator--();
		Fixed		operator--(int);

	static Fixed&			min(Fixed &a, Fixed &b);
	static Fixed& 			max(Fixed &a, Fixed &b);

	static const Fixed&		min(const Fixed &a, const Fixed &b);
	static const Fixed&		max(const Fixed &a, const Fixed &b);

	private:
		int _fixedPoint;
		static const int _fracBits = 8;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);            

#endif 
