#include <iostream>
#include <cstring>

using namespace std;

#pragma once
class Customer
{
public:
	Customer();
	~Customer();
	Customer(unsigned int id, const char* name, const char* address);
	unsigned int getId() const;
	char* getName() const;
	char* getAddress() const;
	void display() const;
private:
	unsigned int id;
	char* name = nullptr;
	char* address = nullptr;
	
	void setAddress(const char* address);
	void setName(const char* name);
};