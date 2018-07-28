#pragma once
#include "PhonebookRecord.h"
#include <ostream>
using namespace std;
class Phonebook
{
public:
	Phonebook(size_t capacity = 10);
	~Phonebook();
	Phonebook(const Phonebook&);

	Phonebook &operator=(const Phonebook&);

	size_t getSize() const;

	size_t getCapacity() const;

	void add(const PhonebookRecord&);

	PhonebookRecord find(const char *);

	friend Phonebook operator+(const Phonebook&, const Phonebook&);

	friend ostream &operator<<(ostream os, const Phonebook&);
private:
	PhonebookRecord * arr;
	size_t size;
	size_t capacity;
	void copy(const Phonebook&);
};