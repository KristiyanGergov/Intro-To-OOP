#pragma once
#include <iostream>

using namespace std;

class Expression
{
public:
	Expression() = default;
	Expression(double val);

	virtual	double value() const = 0;
	virtual void print() const = 0;
	virtual Expression* newInstanceOf() const = 0;
protected:
	double val;
};