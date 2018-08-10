#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Set {

public:
	Set(int capacity = 10);
	~Set();
	Set(const Set& other);
	Set &operator=(const Set& other);

	bool contains(const T &) const;
	Set &add(const T &);
	Set &remove(const T &);
	void print() const;

	int getCapacity() const;
	int getSize() const;
	const T* asArray() const;

private:
	int capacity;
	int size;
	T* arr;

	void copy(const Set&);

	void expand();

	int indexOf(const T& item) const;
};

template<typename T>
Set<T>::Set(int capacity)
{
	this->capacity = capacity;
	this->arr = new T[capacity];
}

template<typename T>
Set<T>::~Set()
{
	delete[] arr;
}

template<typename T>
Set<T>::Set(const Set & other)
{
	copy(other);
}

template<typename T>
Set<T> & Set<T>::operator=(const Set & other)
{
	copy(other);
	return *this;
}

template<typename T>
bool Set<T>::contains(const T & value) const
{
	for (size_t i = 0; i < size; i++)
		if (arr[i] == value)
			return true;
	return false;
}

template<typename T>
Set<T> & Set<T>::add(const T & value)
{
	if (size == capacity)
		expand();
	arr[size] = value;
	size++;
	return *this;
}

template<typename T>
Set<T> & Set<T>::remove(const T & value)
{
	int index = indexOf(value);
	for (size_t i = index; i < size; i++)
		arr[i] = arr[i + 1];
	size--;
	return *this;
}

template<typename T>
void Set<T>::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		cout << i + 1 << ": " << endl << arr[i] << endl;
	}
}

template<typename T>
int Set<T>::getCapacity() const
{
	return this->capacity;
}

template<typename T>
int Set<T>::getSize() const
{
	return this->size;
}

template<typename T>
const T * Set<T>::asArray() const
{
	return this->arr;
}

template<typename T>
void Set<T>::copy(const Set & other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	this->arr = new T[capacity];
	for (size_t i = 0; i < size; i++)
		this->arr[i] = other.arr[i];
}

template<typename T>
void Set<T>::expand()
{
	this->capacity *= 2;
	T* newArr = new T[capacity];
	for (size_t i = 0; i < size; i++)
		newArr[i] = arr[i];
	delete[] arr;
	arr = newArr;
	delete[] newArr;
}

template<typename T>
int Set<T>::indexOf(const T & item) const
{
	for (int i = 0; i < size; i++)
		if (arr[i] == item)
			return i;
	return -1;
}