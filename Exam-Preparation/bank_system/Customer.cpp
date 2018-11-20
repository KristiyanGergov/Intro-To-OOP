#include "Customer.h"

Customer::Customer()
{
	setName("undefined");
	setAddress("undefined");
}

Customer::~Customer()
{
	delete[] name;
	delete[] address;
}

Customer::Customer(unsigned int id, const char * name, const char * address)
{
	this->id = id;
	setName(name);
	setAddress(address);
}

unsigned int Customer::getId() const
{
	return this->id;
}

char * Customer::getName() const
{
	return this->name;
}

char * Customer::getAddress() const
{
	return this->address;
}

void Customer::display() const
{
	cout << "Customer: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
}

void Customer::setAddress(const char * address)
{
	if (this->address)
	{
		delete[] this->address;
		this->address = nullptr;
	}

	if (address)
	{
		int size = strlen(address) + 1;
		this->address = new char[size];
		memcpy(this->address, address, size);
	}
}

void Customer::setName(const char * name)
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