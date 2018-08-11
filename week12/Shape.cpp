#include "Shape.h"
#include "cstring"


Shape::~Shape()
{
}

Shape::Shape(const Shape & other)
{
	strcpy_s(this->color, sizeof other.color, other.color);
}

Shape & Shape::operator=(const Shape & other)
{
	strcpy_s(this->color, sizeof other.color, other.color);
	return *this;
}

Shape::Shape(const char * color)
{
	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, sizeof color, color);
}

char * Shape::getColor() const
{
	return this->color;
}

void Shape::setColor(const char * color)
{
	strcpy_s(this->color, sizeof color, color);
}
