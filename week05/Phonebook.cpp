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

Phonebook operator+(const Phonebook & pb1, const Phonebook &pb2)
{
	Phonebook result = Phonebook(pb1.capacity + pb2.capacity);
	result.size = pb1.size + pb2.size;

	for (size_t i = 0; i < pb1.size; i++) {
		result.arr[i] = pb1.arr[i];
	}

	for (size_t i = 0; i < pb2.size; i++) {
		result.arr[pb1.size + i] = pb2.arr[i];
	}

	return result;
}

ostream & operator<<(ostream os, const Phonebook & pb)
{
	for (size_t i = 0; i < pb.size; i++)
		os << pb.arr[i];
	return os;
}
