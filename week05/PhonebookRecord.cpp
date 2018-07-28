#include "PhonebookRecord.h"
#include <cstring>

PhonebookRecord::PhonebookRecord(const char * name, const char * phoneNumber, const PhoneType phoneType)
{
	strcpy_s(this->name, sizeof name, name);
	strcpy_s(this->phoneNumber, sizeof name, phoneNumber);
	this->phoneType = phoneType;
}

PhonebookRecord::PhonebookRecord(const PhonebookRecord & other)
{
	strcpy(this->name, other.name);
	strcpy(this->phoneNumber, other.phoneNumber);
	this->phoneType = other.phoneType;
}

PhonebookRecord & PhonebookRecord::operator=(const PhonebookRecord & other)
{
	strcpy(this->name, other.name);
	strcpy(this->phoneNumber, other.phoneNumber);
	this->phoneType = other.phoneType;
	return *this;
}

const char * PhonebookRecord::getName()
{
	return this->name;
}

ostream & operator<<(ostream & os, const PhonebookRecord & record)
{
	os << "Name: " << record.name << endl;
	os << "Number: " << record.phoneNumber << endl;
	os << "Type: " << record.phoneType << endl;
	return os;
}

bool operator==(const PhonebookRecord & first, const PhonebookRecord & second)
{
	return !(strcmp(first.name, second.name) || strcmp(first.phoneNumber, second.phoneNumber)) && first.phoneType == second.phoneType;
}

bool operator<(const PhonebookRecord &, const PhonebookRecord &)
{
	return false;
}
