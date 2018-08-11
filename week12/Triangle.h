#pragma once
#include "Shape.h"
class Triangle : public Shape
{
public:
	Triangle();
	~Triangle() = default;

	Triangle(const char* color,  const int a, const int b, const int c);

	Triangle(const Triangle& other);
	Triangle &operator=(const Triangle& other);

	double getArea() const override;

private:
	int a, b, c;
};

