#pragma once
#include "Person.h"

class TaxiDriver : public Person
{
public:
	TaxiDriver()= default;
	~TaxiDriver() = default;
	TaxiDriver(const char* name, const unsigned int age, const  char* carModel);
	TaxiDriver(const TaxiDriver&);
	void greet() const override;

	const char *getCarModel() const;

	void setCarModel(const char *carModel);
private:
	char *carModel;
};