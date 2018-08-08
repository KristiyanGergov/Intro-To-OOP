#include "IntArray.h"


IntArray::~IntArray()
{
	delete[] this->arr;
}

IntArray::IntArray(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->arr = new int[capacity];
}

IntArray::IntArray(const IntArray & other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	delete[] this->arr;
	this->arr = new int[capacity];

	for (size_t i = 0; i < other.size; i++)
		this->arr[i] = other.arr[i];
}

IntArray & IntArray::operator=(const IntArray & other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	delete[] this->arr;
	this->arr = new int[capacity];

	for (size_t i = 0; i < other.size; i++)
		this->arr[i] = other.arr[i];
	return *this;
}

size_t IntArray::getSize() const
{
	return this->size;
}

void IntArray::setSize(const size_t size)
{
	this->size = size;
}

size_t IntArray::getCapacity() const
{
	return this->capacity;
}

void IntArray::setCapacity(const size_t capacity)
{
	this->capacity = capacity;
}

IntArray & IntArray::add(const int value)
{
	if (size == capacity)
	{
		capacity *= 2;
		int* newArr = new int[capacity];
		for (int i = 0; i < size; i++)
			newArr[i] = arr[i];
		delete[] arr;
		arr = newArr;
	}
	this->arr[size] = value;
	size++;
	return *this;
}

IntArray & IntArray::removeLast()
{
	size--;
	return *this;
}

int IntArray::indexOf(const int value)
{
	for (int i = 0; i < size; i++)
		if (arr[i] == value)
			return i;
	return -1;
}

int IntArray::operator[](const int index) const
{
	return arr[index];
}

ostream & operator<<(ostream & os, const IntArray &arr)
{
	os << "[";
	for (size_t i = 0; i < arr.size; i++) {
		os << arr[i];
		if (i == arr.size - 1) {
			os << "]";
		}
		else {
			os << ", ";
		}
	}
	return os;
}
