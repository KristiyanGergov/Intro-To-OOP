#include <iostream>
#include <vector>
#include "Observer.h"
#include "Currency.h"

using namespace std;

#pragma once
class CentralBank
{
public:
	CentralBank();
	~CentralBank();
	CentralBank(const CentralBank& other);
	CentralBank &operator=(const CentralBank& other);

	CentralBank(const char* name);

	vector<Currency*> addCurrency(Currency*);
	vector<Currency*> deleteCurrency(const char* name);
	vector<Observer*> Register(Observer*);
	vector<Observer*> unregister(const char* name);
	void notify(Currency & curr) const;
	void setRate(const char* name, double rate);

private:
	char * name = nullptr;
	void setName(const char* name);

	vector<Currency*> currencies;
	vector<Observer*> observers;

	void clear();
	void copy(const CentralBank& other);

	int indexOfCurrency(const char* name) const;
	int indexOfObserver(const char* name) const;
};