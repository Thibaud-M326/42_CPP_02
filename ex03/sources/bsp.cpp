#include "../includes/Point.hpp"

int crossProduct(Point const a, Point const b, Point const p)
{
	return (b._X() - a._X()) * (p._Y() - a._Y()) - (b._Y() - a._Y()) * (p._X() - a._X());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	int ABP = crossProduct(a, b, point);
	int BCP = crossProduct(b, c, point);
	int CAP = crossProduct(c, a, point);

	if ((ABP > 0 && BCP > 0 && CAP > 0) || (ABP < 0 && BCP < 0 && CAP < 0))
		return true;
	return false;
}