#include "CentralBank.h"

CentralBank::CentralBank()
{
	this->setName("undefined name");
}

CentralBank::~CentralBank()
{
	clear();
}

CentralBank::CentralBank(const CentralBank & other)
{
	copy(other);
}

CentralBank & CentralBank::operator=(const CentralBank & other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

CentralBank::CentralBank(const char * name)
{
	this->setName(name);
}

vector<Currency*> CentralBank::addCurrency(Currency * currency)
{
	if (indexOfCurrency(currency->getName()) != -1)
	{
		cout << "Current curency already exist" << endl;
		return this->currencies;
	}
	currencies.push_back(currency);
	return currencies;
}

vector<Currency*> CentralBank::deleteCurrency(const char * name)
{
	int index = indexOfCurrency(name);
	if (index == -1)
	{
		cout << "Current currency does not exist! Please add it first" << endl;
		return this->currencies;
	}
	currencies.erase(currencies.begin() + index);
	return currencies;
}

vector<Observer*> CentralBank::Register(Observer * observer)
{
	if (indexOfObserver(observer->getName()) != -1)
	{
		cout << "Current observer already exist" << endl;
		return this->observers;
	}
	observers.push_back(observer);
	return observers;
}

vector<Observer*> CentralBank::unregister(const char * name)
{
	int index = indexOfObserver(name);
	if (index == -1)
	{
		cout << "Current observer does not exist! Please add it first" << endl;
		return this->observers;
	}
	observers.erase(observers.begin() + index);
	return observers;
}

void CentralBank::notify(Currency & current) const
{
	for (size_t i = 0; i < observers.size(); i++)
		observers[i]->update(current);
}

void CentralBank::setRate(const char * name, double rate)
{
	int index = indexOfCurrency(name);
	if (index != -1)
	{
		currencies[index]->setRate(rate);
		notify(*currencies[index]);
		return;
	}
	cout << "Current curency does not exist! Please add it first" << endl;
}

void CentralBank::clear()
{
	delete[] this->name;
}

void CentralBank::copy(const CentralBank & other)
{
	this->setName(other.name);

	currencies = vector<Currency*>(other.currencies.size());
	for (size_t i = 0; i < currencies.size(); i++)
	{
		currencies[i] = other.currencies[i];
	}

	observers = vector<Observer*>(other.observers.size());
	for (size_t i = 0; i < observers.size(); i++)
	{
		observers[i] = other.observers[i];
	}
}

int CentralBank::indexOfCurrency(const char * name) const
{
	for (size_t i = 0; i < currencies.size(); i++)
		if (strcmp(currencies[i]->getName(), name) == 0)
			return i;
	return -1;
}

int CentralBank::indexOfObserver(const char * name) const
{
	for (size_t i = 0; i < observers.size(); i++)
		if (strcmp(observers[i]->getName(), name) == 0)
			return i;
	return -1;
}

void CentralBank::setName(const char * name)
{
	if (this->name)
	{
		delete[] this->name;
		this->name = nullptr;
	}
	if (name)
	{
		int size = strlen(name) + 1;
		this->name = new char[size];
		memcpy(this->name, name, size);
	}
}