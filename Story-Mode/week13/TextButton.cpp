#include "TextButton.h"
#include "cstring"

#include <iostream>

using namespace std;

TextButton::TextButton(const char * text)
{
	strcpy_s(this->text, sizeof text, text);
}

void TextButton::draw() const
{
	cout << "Button text: " << this->text << endl;
}