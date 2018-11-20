#pragma once
#include <iostream>

using namespace std;

class Currency
{
public:
	Currency();
	~Currency();
	Currency(const Currency& other);
	Currency &operator=(const Currency& other);

	Currency(const char* name, double rate);
	void print() const;

	char* getName() const;
	void setName(const char* name);

	double getRate() const;
	void setRate(double rate);
private:
	char* name = nullptr;
	double rate;
	void copy(const Currency& other);
	void clear();
};