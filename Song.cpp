#include <stdio.h>
#include <string.h>
#include "Song.h"
#include <iostream>

using namespace std;
/* CONSTRUCTOR
 * 1. Use "New" to allocate proper amount of memory to Artist and Title.
 * 2. Input the Size of the song.
 */
Song::Song()
{
	
}
Song::Song(std::string songArtist, std::string songTitle, int songSize)
{
	artist = songArtist;
	title = songTitle;
	size = songSize;
}
Song::~Song()
{
	
}

void Song::setArtist(std::string songArtist)
{
	artist = songArtist;
}

void Song::setTitle(std::string songTitle)
{
	title = songTitle;
}

void Song::setSize(int songSize)
{
	size = songSize;
}

bool Song::operator == (Song const &rhs)
{
	return((artist == rhs.artist) && (title == rhs.title) && (size == rhs.size));
}

bool Song::operator > (Song const &rhs)
{
	int num;
	if(!(artist == rhs.artist))
	{
		num = artist.compare(rhs.artist);
		return(num > 0);
	}
	else if(!(title == rhs.title))
	{
		num = title.compare(rhs.title);
		return(num > 0);
	}
	else if (!(size == rhs.size))
	{
		return(size > rhs.size);
	}
	return false;
}

bool Song::operator < (Song const &rhs)
{
        int num;
        if(!(artist == rhs.artist))
        {
                num = artist.compare(rhs.artist);
                return(num < 0);
        }
        else if(!(title == rhs.title))
        {
                num = title.compare(rhs.title);
                return(num < 0);
        }
        else if (!(size == rhs.size))
        {
                return(size < rhs.size);
        }
        return false;
}

ostream& operator << (ostream& out, const Song &s)
{
	out << s.getTitle() << " by " << s.getArtist() << " - size of " << s.getSize();
	return out;
}
