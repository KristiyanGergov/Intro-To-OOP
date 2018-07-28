#include "NumSum.h"
#include <iostream>

using namespace std;

int main() {
	NumSum s;
	s.add(10);
	s.sub(10);
	s.sub(2);
	NumSum b(s);
	cout << b.sum() << endl;
	cout << b.changes() << endl;
	cout << b.average() << endl;
	return 0;
}