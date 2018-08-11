#include "TaxiDriver.h"

using namespace std;

TaxiDriver::TaxiDriver(const char * name, const unsigned int age, const char * carModel) : 
	Person(name, age)
{
	this->carModel = new char[strlen(carModel + 1)];
	strcpy_s(this->carModel, sizeof carModel, carModel);
}

TaxiDriver::TaxiDriver(const TaxiDriver & other)
{
	this->age = other.age;
	strcpy_s(this->name, sizeof other.name, other.name);
	strcpy_s(this->carModel, sizeof other.carModel, other.carModel);
}

void TaxiDriver::greet() const
{
	cout << "Calling from taxi driver" << endl;
}

const char * TaxiDriver::getCarModel() const
{
	return this->carModel;
}

void TaxiDriver::setCarModel(const char * carModel)
{
	strcpy_s(this->carModel, sizeof carModel, carModel);
}
