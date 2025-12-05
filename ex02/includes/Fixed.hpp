#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <limits>

class Fixed {

	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed&operator=(const Fixed &other);
		~Fixed();

		Fixed( const int toFixed );
		Fixed( const float toFixed );
		int		toInt( void ) const;
		float	toFloat( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits(int const raw);

		int		operator>(const Fixed &f);
		int		operator<(const Fixed &f);
		int		operator>=(const Fixed &f);
		int		operator<=(const Fixed &f);
		int		operator==(const Fixed &f);
		int		operator!=(const Fixed &f);

		Fixed	operator+(const Fixed &f);
		Fixed	operator-(const Fixed &f);
		Fixed	operator*(const Fixed &f);
		Fixed	operator/(const Fixed &f);

		Fixed&	operator++();
		// Fixed	operator++(int);
		// Fixed	operator--();
		// Fixed	operator--(int);
	private:

		int _fixedPoint;
		float _epsilon;
		static const int _fracBits = 8;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif 
