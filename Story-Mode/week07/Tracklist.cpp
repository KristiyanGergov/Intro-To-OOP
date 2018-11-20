#include "Tracklist.h"
#include <iostream>

using namespace std;

Tracklist::Tracklist(const int capacity)
{
	this->capacity = capacity;
	this->songs = new Song[capacity];
}


Tracklist::~Tracklist()
{
	delete[] songs;
}

Tracklist::Tracklist(const Tracklist & other)
{
	copy(other);
}

Tracklist & Tracklist::operator=(const Tracklist& other)
{
	copy(other);
	return *this;
}

void Tracklist::copy(const Tracklist & other)
{
	for (size_t i = 0; i < size; i++)
		this->songs[i] = other.songs[i];
}

Tracklist& Tracklist::add(const Song & song)
{
	if (size == capacity)
	{
		capacity *= 2;
		Song* newSongs = new Song[capacity];
		for (size_t i = 0; i < size; i++)
			newSongs[i] = songs[i];
		delete[] songs;
		for (size_t i = 0; i < size; i++)
			songs[i] = newSongs[i];
		delete[] newSongs;
	}
	this->songs[size] = song;
	size++;
	return *this;
}

Tracklist& Tracklist::remove(const size_t index)
{
	if (index >= size)
		return *this;

	for (size_t i = index; i < size; i++)
		this->songs[i] = this->songs[i + 1];
	size--;
	return *this;
}

Tracklist& Tracklist::remove(const Song& song)
{
	for (size_t i = 0; i < size; i++)
		if (songs[i] == song)
		{
			remove(i);
			break;
		}
	return *this;
}

ostream & operator<<(ostream & os, const Tracklist & tracklist)
{
	for (size_t i = 0; i < tracklist.size; i++)
	{
		os << "Song " << i + 1 << endl;
		os << tracklist.songs[i];
	}
	return os;
}

istream & operator>>(istream & is, Tracklist & tracklist)
{
	is >> tracklist.capacity >> tracklist.size;
	for (size_t i = 0; i < tracklist.size; i++)
		is >> tracklist.songs[i];
	return is;
}
