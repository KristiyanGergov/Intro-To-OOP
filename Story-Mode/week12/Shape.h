#pragma once
class Shape
{
public:
	Shape() = default;
	virtual ~Shape();

	Shape(const Shape& other);

	Shape &operator=(const Shape& other);

	virtual double getArea() const = 0;

	Shape(const char* color);

	char* getColor() const;
	void setColor(const char* color);
private:
	char* color;
};

