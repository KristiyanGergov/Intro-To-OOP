#include "Expression.h"

#pragma once
class Product : public Expression
{
public:
	Product();
	~Product();
	Product(const Product&);
	Product &operator=(const Product&);

	double value() const override;
	void print() const override;

	Expression* newInstanceOf() const override;

	Product(Expression& first, Expression& second);

private:
	Expression * first;
	Expression * second;

	void copy(const Product&);
	void calculateVal();
	void clear();
};