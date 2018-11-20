#include "Product.h"
#include "Var.h"

Product::Product() : Expression()
{
	this->first = new Var();
	this->second = new Var();
}

Product::~Product()
{
	clear();
}

Product::Product(const Product & other)
{
	copy(other);
}

Product & Product::operator=(const Product & other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

double Product::value() const
{
	return val;
}

void Product::print() const
{
	if (first == nullptr || second == nullptr)
	{
		cout << "incorect" << endl;
		return;
	}
	cout << "(";
	first->print();
	cout << " * ";
	second->print();
	cout << ")";
}

Expression * Product::newInstanceOf() const
{
	return new Product(*this);
}

Product::Product(Expression & first, Expression & second)
{
	this->first = first.newInstanceOf();
	this->second = second.newInstanceOf();
	this->calculateVal();
}

void Product::copy(const Product & other)
{
	this->first = other.first->newInstanceOf();
	this->second = other.second->newInstanceOf();
	this->calculateVal();
}

void Product::calculateVal()
{
	this->val = first->value() * second->value();
}

void Product::clear()
{
	delete this->first;
	delete this->second;
}