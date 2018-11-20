#include "IntArray.h"
#include <iostream>

using namespace std;

int main() {
	IntArray intArray = IntArray(3);
	intArray.add(1).add(2).add(3);
	cout << intArray;
	intArray.removeLast();
	cout << intArray;

	return 0;
}