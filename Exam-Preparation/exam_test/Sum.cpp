#include "Sum.h"

Sum::Sum() : Expression()
{
	this->first = new Var();
	this->second = new Var();
}

Sum::~Sum()
{
	clear();
}

Sum::Sum(const Sum & other)
{
	copy(other);
}

Sum & Sum::operator=(const Sum & other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

double Sum::value() const
{
	return this->val;
}

void Sum::print() const
{
	if (first == nullptr || second == nullptr)
	{
		std::cout << "incorrect" << std::endl;
		return;
	}
	std::cout << "(";
	first->print();
	std::cout << " + ";
	second->print();
	std::cout << ")";
}

Sum::Sum(Expression & first, Expression & second)
{
	this->first = first.newInstanceOf();
	this->second = second.newInstanceOf();
	this->calculateVal();
}

Expression * Sum::newInstanceOf() const
{
	return new Sum(*this);
}

void Sum::copy(const Sum & other)
{
	this->first = other.first->newInstanceOf();
	this->second = other.first->newInstanceOf();
	this->calculateVal();
}

void Sum::clear()
{
	delete this->first;
	delete this->second;
}

void Sum::calculateVal()
{
	this->val = first->value() + second->value();
}