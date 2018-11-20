#include "Const.h"

Const::Const(const double val) : Expression(val)
{
}

void Const::print() const
{
	cout << this->val;
}

double Const::value() const
{
	return this->val;
}

Expression * Const::newInstanceOf() const
{
	return new Const(*this);
}