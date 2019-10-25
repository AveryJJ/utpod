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

	std::string getArtist() const
	{
		return artist;
	}
	std::string getTitle() const
	{
		return title;
	}
	int getSize() const
	{
		return size;
	}
	bool operator == (Song const &rhs);
	bool operator > (Song const &rhs);
	bool operator < (Song const &rhs);
};
std::ostream& operator << (std::ostream& out, const Song &s);

#endif
