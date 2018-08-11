#pragma once

class Color
{
public:
	Color() = default;
	~Color() = default;
	Color(double red, double green, double blue);
	Color(Color& other);
	Color &operator=(Color& other);
private:
	double red;
	double green;
	double blue;
};