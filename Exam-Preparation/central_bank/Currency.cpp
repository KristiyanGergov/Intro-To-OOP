#include "Currency.h"

Currency::Currency()
{
	this->setName("undefined name");
}

Currency::~Currency()
{
	clear();
}

Currency::Currency(const Currency & other)
{
	copy(other);
}

Currency & Currency::operator=(const Currency & other)
{
	if (this != &other)
		copy(other);
	return *this;
}

Currency::Currency(const char * name, double rate)
{
	this->setName(name);
	this->rate = rate;
}

void Currency::print() const
{
	cout << "Currency: " << this->name << endl;
	cout << "Rate: " << this->rate << endl;
}

char * Currency::getName() const
{
	return this->name;
}

void Currency::setName(const char * name)
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

double Currency::getRate() const
{
	return this->rate;
}

void Currency::setRate(double rate)
{
	this->rate = rate;
}

void Currency::copy(const Currency & other)
{
	this->setName(other.getName());
	this->rate = other.getRate();
}

void Currency::clear()
{
	delete[] this->name;
}