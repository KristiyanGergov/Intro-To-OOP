#include "Expression.h"

#pragma once
class Var : public Expression
{
public:
	Var();
	~Var();
	Var(const Var&);
	Var &operator=(const Var&);

	Var(const char* name, double val);
	void print() const override;
	double value() const override;
	void setValue(double val);
	Expression* newInstanceOf() const override;
private:
	char* name = nullptr;
	void copy(const Var&);
	void clear();
	void setName(const char* name);
};