#include "Professor.h"

using namespace std;


Professor::Professor()
{
}


Professor::~Professor()
{
}

Professor::Professor(const char * name, const unsigned int age, const unsigned int papers)
{
	strcpy_s(this->name, sizeof name, name);
	this->age = age;
	this->papers = papers;
}

Professor::Professor(const Professor & other)
{
	strcpy_s(this->name, sizeof other.name, other.name);
	this->age = other.age;
	this->papers = other.papers;
}

Professor & Professor::operator=(const Professor & other)
{
	strcpy_s(this->name, sizeof other.name, other.name);
	this->age = other.age;
	this->papers = other.papers;
	return *this;
}

void Professor::greet() const
{
	cout << "I am a professor. Big deal" << endl;
}

unsigned int Professor::getPapers() const
{
	return this->papers;
}

void Professor::setPapers(unsigned int papers)
{
	this->papers = papers;
}



std::ostream & operator<<(std::ostream & os, const Professor & professor)
{
	os << (Person &)professor << "Papers: " << professor.papers;
	return os;
}