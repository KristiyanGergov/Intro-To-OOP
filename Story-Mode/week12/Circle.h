#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle() = default;
	~Circle() = default;

	Circle(const char *color, double radius);

	Circle(const Circle &);

	Circle &operator=(const Circle &);


	double getArea() const override;

private:
	double r;
};

