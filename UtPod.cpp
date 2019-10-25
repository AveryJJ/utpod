#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

UtPod::UtPod()
{
	songs = NULL;
	memSize = MAX_MEMORY;
}

UtPod::UtPod(int size)
{
	songs = NULL;
	if((size > MAX_MEMORY) || (size <= 0))
	{
		size = MAX_MEMORY;
	}
}
UtPod::~UtPod()
{
	clearMemory();
}
/*
 * IF THERE IS ENOUGH MEMORY
 * 1. create new SongNode
 * 2. Set Songs (head Pointer) to new SongNode
 * 3. Set song info of NewNode to the passed in songs info
 * 4. Set NewNodes next pointer to previous Head
 */
int UtPod::addSong(Song const &s)
{
	if(UtPod::getRemainingMemory() <= memSize)
	{
		SongNode *temp = new SongNode;
		temp->next = songs;
		songs = temp;
		temp->s.setArtist(s.getArtist());
		temp->s.setTitle(s.getTitle());
		temp->s.setSize(s.getSize());
		return 0;
	}
	else
	{
		return 1;
	}
}

int UtPod::removeSong(Song const &s)
{
	if(songs == NULL)
	{
		return 1;
	}
	else
	{
		SongNode *FollowPtr = songs;
		SongNode *LeadPtr = songs;
		while(FollowPtr != NULL)
		{
			if((LeadPtr->s.getTitle() == s.getTitle()) && (LeadPtr->s.getArtist() == s.getArtist()) && (LeadPtr->s.getSize() == s.getSize()))
			{
				if(FollowPtr == songs)
				{
					songs = songs->next;
					delete FollowPtr;
					return 0;
				}
				else
				{
					FollowPtr->next = LeadPtr->next;
					delete LeadPtr;
					return 0;
				}
			}
			LeadPtr = FollowPtr->next;
			FollowPtr = FollowPtr->next;
			LeadPtr = LeadPtr->next;
		}

	}
	return 1;
}

void UtPod::shuffle()
{

}

void UtPod::showSongList()
{
	if(songs == NULL)
	{
		cout<<"list is empty"<<endl;
	}
	else
	{
		SongNode *ptr = songs;
		while(ptr != NULL)
		{
			cout << ptr->s.getTitle() << " by " << ptr->s.getArtist() << "size of: " << ptr->s.getSize() << endl;
			ptr = ptr->next;
		}
	}
}

void UtPod::sortSongList()
{
	
}

void UtPod::clearMemory()
{
        if(songs == NULL)
        {
                return;
        }
        else
        {
                SongNode *ptr = songs;
                while(ptr != NULL)
                {
                        SongNode *temp = ptr;
                        delete temp;
                        ptr = ptr->next;
                }
                songs = ptr;
	}
}

int UtPod::getRemainingMemory()
{
	int curSize = 0;
	if(songs == NULL)
	{
		return memSize;
	}
	else
	{
		SongNode *ptr = songs;
		while(ptr != NULL)
		{
			curSize += ptr->s.getSize();
			ptr = ptr->next;
		}
	}
	return memSize - curSize;
}

