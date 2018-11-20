#include "Song.h"
#include "Tracklist.h"
#include <iostream>

using namespace std;

int main() {
	Song song = Song("gosho", "tosho", 5);
	Song song1 = Song("gosho1", "tosho1", 5);
	Song song2 = Song("gosho2", "tosho2", 5);
	Song song3 = Song("gosho3", "tosho3", 5);

	Tracklist tracklist = Tracklist();
	tracklist.add(song).add(song1).add(song2).add(song3);
	tracklist.remove(song3);

	cout << tracklist;
	return 0;
}