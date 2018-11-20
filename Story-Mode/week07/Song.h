#pragma once
#include <ostream>
#include <istream>

using namespace std;

class Song
{
public:

	Song() = default;

	Song(const char* name, const char* artist, const unsigned int duration);

	Song(const Song&);

	Song &operator=(const Song&);

	friend bool operator==(const Song& first, const Song& second);

	friend ostream& operator<<(ostream& os, const Song& song);
	friend istream& operator>>(istream& is, Song& song);

private:
	char name[50];
	char artist[50];
	unsigned int duration;
};