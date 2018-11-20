#pragma once
class View
{
public:
	virtual ~View();
	View(View& other);
	View &operator=(View& other);
	View(double x = 0, double y = 0, double sizeX = 0, double sizeY = 0);
	virtual void draw() const;
protected:
	double x;
	double y;
	double sizeX;
	double sizeY;
};

