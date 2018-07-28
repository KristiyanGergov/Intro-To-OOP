#include "Phonebook.h"
#include <cstring>


Phonebook::Phonebook(size_t capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->arr = new PhonebookRecord[capacity];
}


Phonebook::~Phonebook()
{
	delete[] arr;
}

Phonebook::Phonebook(const Phonebook & other)
{
	copy(other);
}

Phonebook & Phonebook::operator=(const Phonebook & other) {

	if (this != &other) {
		delete[] arr;
		copy(other);
	}

	return *this;
}

size_t Phonebook::getSize() const
{
	return this->size;;
}

size_t Phonebook::getCapacity() const
{
	return this->capacity;
}

void Phonebook::add(const PhonebookRecord & value)
{
	if (++size == capacity)
	{
		capacity *= 2;
		PhonebookRecord *newRecord = new PhonebookRecord[capacity];
		for (size_t i = 0; i < size; i++)
			newRecord[i] = arr[i];

		delete[] arr;
		arr = newRecord;
		delete[] newRecord;
	}
	arr[size] = value;
}

PhonebookRecord Phonebook::find(const char * query)
{
	for (size_t i = 0; i < size; i++)
		if (strcmp(query, arr[i].getName()) == 0)
			return arr[i];
}

void Phonebook::copy(const Phonebook & other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->arr = new PhonebookRecord[other.capacity];

	for (size_t i = 0; i < other.size; i++)
		this->arr[i] = other.arr[i];
}

ostream & operator<<(ostream os, const Phonebook & pb)
{
	for (size_t i = 0; i < pb.size; i++)
		os << pb.arr[i];
}
