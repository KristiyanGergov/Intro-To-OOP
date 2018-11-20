#include "Button.h"
#include <iostream>

using namespace std;

const int Button::SIZE_X = 250;
const int Button::SIZE_Y = 100;

Button::~Button()
{
	cout << "Destructing view at " << (long)this << endl;
}

Button::Button(const Color & color, double x, double y)
{
	this->x = x;
	this->y = y;
	this->color = color;
}

void Button::draw() const
{
	cout << "x: " << x << endl << "y: " << y << endl;
}

void Button::clicked() const
{
	cout << "Clicked" << endl;
}
