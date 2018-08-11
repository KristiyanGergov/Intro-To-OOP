#include "Button.h"
#include <iostream>

using namespace std;

const int Button::SIZE_X = 250;
const int Button::SIZE_Y = 100;


Button::Button(Color color, double x, double y) : View(x, y, SIZE_X, SIZE_Y), color(color)
{

}

void Button::draw() const
{
	cout << "x: " << x << endl << "y: " << y << endl;
}

void Button::clicked() const
{
	cout << "Clicked" << endl;
}
