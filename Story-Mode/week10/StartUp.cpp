#include "Person.h"
#include "Professor.h"
#include "TaxiDriver.h"

#include <iostream>

using namespace std;
int main() {
	Person professor = Professor("Gosho", 43, 10);
	Person taxiDriver = TaxiDriver("Shiso", 45, "bmw");
	
	taxiDriver.greet();

	return 0;
}