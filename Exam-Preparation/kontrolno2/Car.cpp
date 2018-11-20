#include "Car.h"

Car::Car() : Vehicle()
{
	this->setOwnerName("undefined");
}

Car::~Car()
{
	delete[] this->ownerName;
}

Car::Car(const Car & other) : Vehicle(other)
{
	this->setOwnerName(other.ownerName);
	this->fuelConsumption = other.fuelConsumption;
}

Car & Car::operator=(const Car & other)
{
	if (this != &other)
	{
		Vehicle::operator=(other);
		this->setOwnerName(other.ownerName);
		this->fuelConsumption = other.fuelConsumption;
	}
	return *this;
}

Car::Car(const char * make, const char * model, unsigned int maxSpeed, unsigned int seats, const char * ownerName, double fuelConsumption)
	:Vehicle(make, model, maxSpeed, seats)
{
	this->setOwnerName(ownerName);
	this->fuelConsumption = fuelConsumption;
}

char * Car::getOwnerName() const
{
	return this->ownerName;
}

double Car::getFuelConsumtpion() const
{
	return this->fuelConsumption;
}

void Car::setOwnerName(const char * ownerName)
{
	if (this->ownerName)
	{
		delete[] this->ownerName;
		this->ownerName = nullptr;
	}
	if (ownerName)
	{
		int size = strlen(ownerName) + 1;
		this->ownerName = new char[size];
		memcpy(this->ownerName, ownerName, size);
	}
}

void Car::setFuelConsumtion(double fuelConsumtpion)
{
	this->fuelConsumption = fuelConsumption;
}

double Car::getMpg() const
{
	return (fuelConsumption / 3.785);
}

bool operator<(const Car & left, const Car & right)
{
	return left.getMpg() < right.getMpg();
}

ostream & operator<<(ostream& os, const Car & car)
{
	const Vehicle& v(car);
	os << v;
	os << "Owner name: " << car.ownerName << endl;
	os << "Fuel consumption: " << car.fuelConsumption << endl;
	return os;
}