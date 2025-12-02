#ifndef FIXED_H
#define FIXED_H

class Fixed {

	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		Fixed( const int toFixed );
		Fixed( const float toFixed );
		int		toInt( void ) const;
		float	toFloat( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits(int const raw);

	private:

		int _fixedPoint;
		static const int _fracBits = 8;
};

#endif
