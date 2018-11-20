#include <iostream>
#include <ostream>

using namespace std;
#pragma once
class Vehicle
{
public:
	Vehicle();
	virtual ~Vehicle();
	Vehicle(const Vehicle& other);
	Vehicle &operator=(const Vehicle& other);

	Vehicle(const char*make, const char* model, unsigned int maxSpeed, unsigned int seats);


	char* getMake() const;
	char* getModel() const;
	unsigned int getMaxSpeed() const;
	unsigned int getSeats() const;

	void setMake(const char* make);
	void setModel(const char* model);
	void setMaxSpeed(unsigned int maxSpeed);
	void setSeats(unsigned int seats);


	friend bool operator< (const Vehicle& left, const Vehicle& right);

	friend ostream &operator<<(ostream& os, const Vehicle&);

private:
	char* make = nullptr;
	char* model = nullptr;
	unsigned int maxSpeed;
	unsigned int seats;
};