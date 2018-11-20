#include "Vehicle.h"
#include "Car.h"

#include <iostream>

using namespace std;

int main() {

	Vehicle v = Vehicle("bmw", "m5", 360, 5);
	Car c = Car("audi", "R8", 400, 2, "Pesho", 15);
	Car c1 = Car("audi", "R8", 400, 2, "Pesho", 14);

	bool yes = c < c1;
	cout << (bool)yes << endl;


	cout << v << endl;
	cout << c;

	return 0;
}