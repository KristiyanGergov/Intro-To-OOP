#include "Expression.h"
#include "Const.h"
#include "Var.h"
#include "Product.h"
#include "Sum.h"
#include <iostream>

using namespace std;

int main() {
	Const pi(3.14);
	
	Var x("x", 3);
	Var y("y", 4);
	Var z("z", 5);

	Sum sum(pi, x);
	Product product(x, y);

	Sum first(x, y);
	Product second(z, x);
	Sum third(first, second);
	Product last(third, x);
	Sum reallyLast(last, y);

	reallyLast.print();
	cout << endl;
	cout << "Value: " << reallyLast.value() << endl;
	return 0;
}