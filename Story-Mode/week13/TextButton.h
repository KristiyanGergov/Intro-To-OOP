#pragma once
#include "Button.h"

class TextButton : Button
{
public:
	TextButton() = default;
	~TextButton() = default;

	TextButton(const char* text);

	void draw() const override;

private: 
	char* text;
};

