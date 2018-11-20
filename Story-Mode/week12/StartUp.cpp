#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"

#include <iostream>
#include <cassert>

using namespace std;

int main() {
	Circle c1("blue", 1);
	Triangle t1("red", 3, 4, 5);

	cout << c1.getArea() << endl;

	cout << t1.getArea() << endl;

	const Shape *shapes[] = { &t1, &c1 };



	return 0;
}