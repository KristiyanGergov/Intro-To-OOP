#pragma once
class View
{
public:
	View();
	View(View& other);
	View &operator=(View& other);
	View(double x, double y, double sizeX, double sizeY);
	virtual ~View() = default;
	virtual void draw() const;
protected:
	double x;
	double y;
	double sizeX;
	double sizeY;
};

