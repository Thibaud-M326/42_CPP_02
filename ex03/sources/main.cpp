#include "../includes/Point.hpp"
#include "../includes/Fixed.hpp"
#include "../includes/bsp.hpp"
#include <iostream>

int main() 
{

	Point const a(0, 0);
	Point const b(4, 0);
	Point const c(2, 3);

	Point const insideP(2, 1);

	Point const outsideP(-2, 1);

	int isInsideP;
	
	isInsideP = bsp(a, b, c, insideP);
	// isInsideP = bsp(a, b, c, outsideP);

	if (isInsideP)
		std::cout << "point in inside triangle" << std::endl;
	else 
		std::cout << "point in outside triangle" << std::endl;
	
	return 0;
}
