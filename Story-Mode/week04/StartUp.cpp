#include "Tuple.h"
#include "NTuple.h"
#include <iostream>

using namespace std;

int main() {
	NTuple threeTuple1 = NTuple(3); // [0, 0, 0]
	threeTuple1.print();
	threeTuple1.setComponent(0, 5); // becomes [5, 0, 0]

	NTuple threeTuple2 = NTuple(threeTuple1); // initialized with [5, 0, 0]
	threeTuple2.setComponent(0, 2); // becomes [2, 0, 0]
	threeTuple2.setComponent(1, 2); // becomes [2, 2, 0]
	threeTuple2.setComponent(2, 2); // becomes [2, 2, 2]
	threeTuple2.print();

	threeTuple2 *= 3; // becomes [6, 6, 6]
	threeTuple2.print();

	threeTuple1 += threeTuple2; // threeTuple1 becomes [11, 6, 6]
	threeTuple1.print();
	return 0;
}