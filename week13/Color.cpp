#include "Color.h"

Color::Color(double red, double green, double blue)
{
	this->red = red;
	this->blue = blue;
	this->green = green;
}

Color::Color(Color & other)
{
	this->red = other.red;
	this->blue = other.blue;
	this->green = other.green;
}

Color & Color::operator=(Color & other)
{
	if (this != &other)
	{
		this->red = other.red;
		this->blue = other.blue;
		this->green = other.green;
	}
	return *this;
}
