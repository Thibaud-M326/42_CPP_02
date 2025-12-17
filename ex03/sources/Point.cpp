#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

Point::Point() 
:
	_x(0),
	_y(0)
{}

Point::Point(const float a, const float b)
:
	_x(a),
	_y(b)
{}

Point::Point(const Point &copy)
:
	_x(copy._x),
	_y(copy._y)
{}

Point& Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

Point::~Point() {}