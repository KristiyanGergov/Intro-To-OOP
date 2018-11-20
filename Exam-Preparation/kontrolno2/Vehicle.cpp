#include "Vehicle.h"

Vehicle::Vehicle()
{
	this->setMake("undefined");
	this->setModel("undefined");
}

Vehicle::~Vehicle()
{
	delete[] this->make;
	delete[] this->model;
}

Vehicle::Vehicle(const Vehicle & other)
{
	this->setMake(other.make);
	this->setModel(other.model);
	this->maxSpeed = other.maxSpeed;
	this->seats = other.seats;
}

Vehicle & Vehicle::operator=(const Vehicle & other)
{
	if (this != &other)
	{
		this->setMake(other.make);
		this->setModel(other.model);
		this->maxSpeed = other.maxSpeed;
		this->seats = other.seats;
	}
	return *this;
}

Vehicle::Vehicle(const char * make, const char * model, unsigned int maxSpeed, unsigned int seats)
{
	this->setMake(make);
	this->setModel(model);
	this->maxSpeed = maxSpeed;
	this->seats = seats;
}

char * Vehicle::getMake() const
{
	return this->make;
}

char * Vehicle::getModel() const
{
	return this->model;
}

unsigned int Vehicle::getMaxSpeed() const
{
	return this->maxSpeed;
}

unsigned int Vehicle::getSeats() const
{
	return this->seats;
}

void Vehicle::setMake(const char * make)
{
	if (this->make)
	{
		delete[] this->make;
		this->make = nullptr;
	}
	if (make)
	{
		int size = strlen(make) + 1;
		this->make = new char[size];
		memcpy(this->make, make, size);
	}
}

void Vehicle::setModel(const char * model)
{
	if (this->model)
	{
		delete[] this->model;
		this->model = nullptr;
	}
	if (model)
	{
		int size = strlen(model) + 1;
		this->model = new char[size];
		memcpy(this->model, model, size);
	}
}

void Vehicle::setMaxSpeed(unsigned int maxSpeed)
{
	this->maxSpeed = maxSpeed;
}

void Vehicle::setSeats(unsigned int seats)
{
	this->seats = seats;
}

bool operator<(const Vehicle & left, const Vehicle & right)
{
	return left.maxSpeed < right.maxSpeed;
}

ostream & operator<<(ostream& os, const Vehicle & vehicle)
{
	os << "Make: " << vehicle.make << endl;
	os << "Model: " << vehicle.model << endl;
	os << "Max speed: " << vehicle.maxSpeed << endl;
	os << "Seats: " << vehicle.seats << endl;
	return os;
}