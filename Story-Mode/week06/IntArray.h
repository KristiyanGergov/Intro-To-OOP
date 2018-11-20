#include <ostream>

using namespace std;

#pragma once
class IntArray
{
public:
	~IntArray();
	IntArray(int capacity = 10);
	IntArray(const  IntArray&);
	IntArray &operator=(const IntArray&);

	size_t getSize() const;
	void setSize(const size_t size);

	size_t getCapacity() const;
	void setCapacity(const size_t capacity);

	IntArray &add(const int value);
	IntArray &removeLast();
	int indexOf(const int value);
	int operator[](const int index) const;

	friend ostream& operator<<(ostream &os, const IntArray& arr);

private:
	int *arr;
	size_t size;
	size_t capacity;
};