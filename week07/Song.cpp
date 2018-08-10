#include "Song.h"
#include "cstring"


Song::Song(const char * name, const char * artist, const unsigned int duration)
{
	strcpy(this->name, name);
	strcpy(this->artist, artist);
	this->duration = duration;
}

Song::Song(const Song & other)
{
	strcpy(this->name, other.name);
	strcpy(this->artist, other.artist);
	this->duration = other.duration;
}

Song & Song::operator=(const Song & other)
{
	strcpy(this->name, other.name);
	strcpy(this->artist, other.artist);
	this->duration = other.duration;
	return *this;
}

bool operator==(const Song & first, const Song & second)
{
	if ((strcmp(first.artist, second.artist) == 0) && (strcmp(first.name, second.name) == 0))
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

istream &operator>>(istream & is, Song & song)
{
	is >> song.name >> song.artist >> song.duration;

	return is;
}