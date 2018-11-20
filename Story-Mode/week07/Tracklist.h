#pragma once
#include "Song.h"
#include <ostream>
#include <istream>

using namespace std;

class Tracklist
{
public:
	Tracklist(const int capacity = 10);
	~Tracklist();
	Tracklist(const Tracklist& other);
	Tracklist &operator=(const Tracklist& other);
	void copy(const Tracklist &other);
	Tracklist &add(const Song& song);
	Tracklist &remove(const size_t index);
	Tracklist &remove(const Song& song);

	friend ostream &operator<<(ostream& os, const Tracklist& tracklist);
	friend istream &operator>>(istream& is, Tracklist& tracklist);

private:
	Song * songs;
	int size;
	int capacity;
};