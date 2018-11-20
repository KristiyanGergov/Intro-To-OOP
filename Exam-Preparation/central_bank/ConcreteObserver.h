#include "Observer.h"
#include <iostream>
using namespace std;

#pragma once
class ConcreteObserver : public Observer
{
public:
	ConcreteObserver();
	~ConcreteObserver();
	ConcreteObserver(const ConcreteObserver& other);
	ConcreteObserver &operator=(const ConcreteObserver& other);

	ConcreteObserver(const char* name);

	void update(Currency&) const override;
	
	char* getName() const override;
	
	Observer* newInstanceOf() const override;
private:
	char* name = nullptr;
	void setName(const char* name);
	void clear();
	void copy(const ConcreteObserver& other);
};