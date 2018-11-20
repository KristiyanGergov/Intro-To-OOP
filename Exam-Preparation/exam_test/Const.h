#include "Expression.h"

#pragma once
class Const : public Expression
{
public:
	Const() = default;
	Const(const double val);
	void print() const override;
	double value() const override;
	Expression* newInstanceOf() const override;
};