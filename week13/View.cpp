#include "View.h"
#include <iostream>

using namespace std;

View::View(View & other) :
	x(other.x), y(other.y), sizeX(other.sizeX), sizeY(other.sizeY)
{
}

View & View::operator=(View & other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
		this->sizeX = other.sizeX;
		this->sizeY = other.sizeY;
	}
	return *this;
}

View::View(double x, double y, double sizeX, double sizeY) :
	x(x), y(y), sizeX(sizeX), sizeY(sizeY)
{
}

View::~View()
{
	cout << "Destructing view at address" << (long)this << endl;
}

void View::draw() const
{
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	std::cout << "sizeX: " << sizeX << std::endl;
	std::cout << "sizeY: " << sizeY << std::endl;
}