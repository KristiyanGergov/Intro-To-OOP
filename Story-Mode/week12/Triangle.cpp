#include "Triangle.h"
#include <cmath>

Triangle::Triangle()
{
}

Triangle::Triangle(const char* color, const int a, const int b, const int c) : Shape(color), a(a), b(b), c(c)
{

}

Triangle::Triangle(const Triangle & other) : Shape(other), a(other.a), b(other.b), c(other.c)
{
}

Triangle & Triangle::operator=(const Triangle & other)
{
	if (this != & other)
	{
		Shape::operator=(other);
		this->a = other.a;
		this->b = other.b;
		this->c = other.c;
	}
	return *this;
}

double Triangle::getArea() const
{
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
