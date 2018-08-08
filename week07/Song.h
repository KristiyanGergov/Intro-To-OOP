#pragma once
#include <ostream>

using namespace std;

class Song
{
public:

	Song(const char* name, const char* artist, const unsigned int duration);

	Song(const Song&);

	Song &operator=(const Song&);

	friend bool operator==(const Song& first, const Song& second);
	friend ostream& operator<<(ostream& os, const Song& song);


private:
	char name[50];
	char artist[50];
	unsigned int duration;
};