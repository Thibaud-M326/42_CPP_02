#ifndef POINT_H
#define POINT_H

#include "../includes/Fixed.hpp"

class Point {
	
	public:
		Point();
		Point(const float a, const float b);

		Point(const Point &copy);
		Point&	operator=(const Point &other);

		~Point();

		int		_X( void ) const {return (_x.getRawBits());};
		int		_Y( void ) const {return (_y.getRawBits());};

	private:
		const Fixed _x;
		const Fixed _y;

};

#endif