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
Song::Song(std::string songArtist, std::string songString, int songSize)
{
	artist = songArtist;
	title = songTitle;
	size = songSize;
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
