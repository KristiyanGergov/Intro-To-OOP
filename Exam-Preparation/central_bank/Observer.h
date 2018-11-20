#pragma once
#include "Currency.h"

class Observer
{
public:
	virtual void update(Currency &) const = 0;
	virtual char* getName() const = 0;
	virtual Observer* newInstanceOf() const = 0;
};