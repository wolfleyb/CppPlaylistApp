#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song
{
public:
	Song(string sName = "none", string sFirstLine = "none");
	void PlaySong();
	string GetName();
	string GetFirstLine();
	int GetPlays();

private:
	string	songName;
	string	songFirstLine;
	int		numPlays;

};

#endif