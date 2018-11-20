#pragma once
#include "Color.h"
#include "View.h"

#define WHITE Color(1,1,1);

class Button : public View
{
public:
	static const int SIZE_X;
	static const int SIZE_Y;

	~Button() override;

	Button(const Color &color, double x = 0, double y = 0);

	void draw() const override;

	void clicked() const;

private:
	Color color;
};

