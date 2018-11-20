#include "Tuple.h"
#include <iostream>

using namespace std;

Tuple::Tuple()
{
	this->a = 0;
	this->b = 0;
}

Tuple::Tuple(const Tuple & other)
{
	this->a = other.a;
	this->b = other.b;
}

Tuple & Tuple::operator=(const Tuple & other)
{
	this->a = other.a;
	this->b = other.b;
	return *this;
}


Tuple::~Tuple()
{
	this->a = 0;
	this->b = 0;
}

Tuple::Tuple(int a, int b)
{
	this->a = a;
	this->b = b;
}

const int Tuple::getA() const
{
	return this->a;
}

const int Tuple::getB() const
{
	return this->b;
}

void Tuple::setA(const int a)
{
	this->a = a;
}

void Tuple::setB(const int b)
{
	this->b = b;
}

void Tuple::print() const
{
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
}

long Tuple::sum() const
{
	return a + b;
}

double Tuple::average() const
{
	return (a + b) / 2.0;
}

void Tuple::incrementBy(const Tuple &tuple)
{
	this->a += tuple.a;
	this->b += tuple.b;
}

void Tuple::multiplyBy(const Tuple &tuple)
{
	this->a *= tuple.a;
	this->b *= tuple.b;
}

void Tuple::operator+=(const Tuple & other)
{
	incrementBy(other);
}

void Tuple::operator*=(const Tuple & other)
{
	multiplyBy(other);
}

void Tuple::operator*=(int scalar)
{
	this->a *= scalar;
	this->b *= scalar;
}
