#pragma once
#include "Expression.h"
#include "Var.h"

class Sum : public Expression
{
public:
	Sum();
	~Sum();
	Sum(const Sum& other);
	Sum &operator=(const Sum& other);

	double value() const override;
	void print() const override;

	Sum(Expression& first, Expression& second);
	Expression* newInstanceOf() const override;

private:
	Expression * first = nullptr;
	Expression * second = nullptr;
	void copy(const Sum& other);
	void clear();
	void calculateVal();
};