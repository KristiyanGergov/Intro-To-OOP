#include "Vehicle.h"

#pragma once
class Car : public Vehicle
{
public:
	Car();
	~Car();
	Car(const Car& other);
	Car &operator=(const Car& other);

	Car(const char* make, const char* model, unsigned int maxSpeed, unsigned int seats, const char* ownerName, double fuelConsumption);

	char* getOwnerName() const;
	double getFuelConsumtpion() const;

	void setOwnerName(const char* ownerName);
	void setFuelConsumtion(double fuelConsumtpion);

	double getMpg() const;

	friend bool operator<(const Car& left, const Car& right);
	friend ostream &operator<<(ostream& os, const Car&);

private:
	char* ownerName = nullptr;
	double fuelConsumption;
};