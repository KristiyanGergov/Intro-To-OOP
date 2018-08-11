#include "Person.h"
#include <cstring>

using namespace std;

Person::Person(const char * name, unsigned int age)
{
	cout << "Person constructor called" << std::endl;
	strcpy_s(this->name, sizeof name, name);
	this->age = age;
}

Person::Person(const Person & other)
{
	cout << "Person copy constructor called" << std::endl;
	strcpy_s(this->name, sizeof other.name, other.name);
	this->age = other.age;
}

Person & Person::operator=(const Person & other)
{
	if (this != &other)
	{
		strcpy_s(this->name, sizeof other.name, other.name);
		this->age = other.age;
	}
	return *this;
}

Person::~Person()
{
	cout << "Person destructor called" << endl;
}

void Person::greet() const
{
	cout << "Hello, my name is " << name << ". I am " << age << " years old.";
}

unsigned int Person::getAge() const
{
	return this->age;
}

void Person::setAge(unsigned int age)
{
	this->age = age;
}

const char * Person::getName() const
{
	return this->name;
}

void Person::setName(const char * name)
{
	strcpy_s(this->name, sizeof name, name);
}

std::ostream & operator<<(std::ostream &os, const Person &person)
{
	os << "Name: " << person.name << endl;
	os << "Age: " << person.age << endl;
	return os;
}
