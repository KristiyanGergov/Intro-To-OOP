#include "Person.h"
#include "Professor.h"

#include <iostream>

using namespace std;
int main() {
	Professor professor = Professor("Gosho", 43, 10);

	professor.setName("qko");
	cout << professor << endl;
	return 0;
}