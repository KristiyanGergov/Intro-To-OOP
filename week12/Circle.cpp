#include "Circle.h"

#define _USE_MATH_DEFINES
#include <cmath>


Circle::Circle(const char * color, double radius) : Shape(color)
{
	this->r = radius;
}

Circle::Circle(const Circle & other) : Shape(other)
{
	this->r = other.r;
}

Circle & Circle::operator=(const Circle & other)
{
	if (this != &other)
	{
		Shape::operator=(other);
		this->r = other.r;
	}
	return *this;
}

double Circle::getArea() const {
	return M_PI * r * r;
}
