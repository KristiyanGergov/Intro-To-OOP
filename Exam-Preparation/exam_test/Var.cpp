#include "Var.h"
#include <cstring>

Var::Var()
{
	setName("deff");
}

Var::Var(const char * name, double val) : Expression(val)
{
	setName(name);
}

Var::~Var()
{
	clear();
}

Var::Var(const Var & var)
{
	copy(var);
}

Var & Var::operator=(const Var & other)
{
	if (this != &other)
		copy(other);
	return *this;
}

void Var::print() const
{
	cout << val;
}

double Var::value() const
{
	return this->val;
}

void Var::setValue(double val)
{
	this->val = val;
}

Expression * Var::newInstanceOf() const
{
	return new Var(*this);
}

void Var::copy(const Var & other)
{
	this->val = other.val;
	this->setName(other.name);
}

void Var::clear()
{
	delete[] this->name;
}

void Var::setName(const char* name)
{
	if (this->name)
	{
		delete[] this->name;
		this->name = nullptr;
	}

	if (name)
	{
		int size = strlen(name) + 1;
		this->name = new char[size];
		memcpy(this->name, name, size);
	}
}