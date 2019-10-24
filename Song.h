#include <cstdlib>
#include <iostream>

#ifndef Song_H
#define Song_H

class Song
{
private:
	std::string artist;
	std::string title;
	int size;
public:
	Song();
	Song(std::string songArtist, std::string songTitle, int Size);
	~Song();

	void setArtist(std::string);
	void setTitle(std::string);
	void setSize(int);

	std::string getArtist()
	{
		return artist;
	}

	std::string getTitle()
	{
		return title;
	}

	int getSize()
	{
		return size;
	}
};
#endif
