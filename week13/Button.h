#pragma once
#include "Color.h"
#include "View.h"

class Button : public View
{
public:
	static const int SIZE_X;
	static const int SIZE_Y;

	Button() = default;
	~Button() = default;

	Button(Color color, double x, double y);

	void draw() const override;

	void clicked() const;

private:
	Color color;
};

