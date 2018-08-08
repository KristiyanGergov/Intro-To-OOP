#include "Song.h"
#include <iostream>

using namespace std;

int main() {
	Song song = Song("gosho", "tosho", 5);

	cout << song << endl;
	return 0;
}