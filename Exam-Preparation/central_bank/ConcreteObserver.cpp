#include "ConcreteObserver.h"

ConcreteObserver::ConcreteObserver()
{
	this->setName("undefined name");
}

ConcreteObserver::~ConcreteObserver()
{
	clear();
}

ConcreteObserver::ConcreteObserver(const ConcreteObserver & other)
{
	this->copy(other);
}

ConcreteObserver & ConcreteObserver::operator=(const ConcreteObserver & other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

ConcreteObserver::ConcreteObserver(const char * name)
{
	this->setName(name);
}

void ConcreteObserver::update(Currency & currency) const
{
	cout << "Update: " << this->name << endl;
	currency.print();
}

char * ConcreteObserver::getName() const
{
	return this->name;
}

Observer * ConcreteObserver::newInstanceOf() const
{
	return new ConcreteObserver(*this);
}

void ConcreteObserver::setName(const char * name)
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

void ConcreteObserver::clear()
{
	delete[] this->name;
}

void ConcreteObserver::copy(const ConcreteObserver & other)
{
	this->setName(other.getName());
}