#include "Song.h"
#include "cstring"


Song::Song(const char * name, const char * artist, const unsigned int duration)
{
	strcpy_s(this->name, sizeof name, name);
	strcpy_s(this->artist, sizeof name, artist);
	this->duration = duration;
}

Song::Song(const Song & other)
{
	strcpy_s(this->name, sizeof name, other.name);
	strcpy_s(this->artist, sizeof name, other.artist);
	this->duration = other.duration;
}

Song & Song::operator=(const Song & other)
{
	strcpy_s(this->name, sizeof name, other.name);
	strcpy_s(this->artist, sizeof name, other.artist);
	this->duration = other.duration;
	return *this;
}

bool operator==(const Song & first, const Song & second)
{
	if (strcmp(first.artist, second.artist) && strcmp(first.name, second.name))
		return true;
	return false;
}

ostream & operator<<(ostream & os, const Song & song)
{
	os << "Artist: " << song.artist << endl;
	os << "Song: " << song.name << endl;
	os << "Duration: " << song.duration << endl;
	return os;
}
