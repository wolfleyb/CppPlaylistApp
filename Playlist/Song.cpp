#include "pch.h"
#include <iostream>
#include <string>
#include "Song.h"
using namespace std;

Song::Song(string sName, string sFirstLine)
{
	songName = sName;
	songFirstLine = sFirstLine;
	numPlays = 0;
}

void Song::PlaySong()
{
	cout << this->songFirstLine << endl;
	numPlays++;
}

string Song::GetName()
{
	return songName;
}

string Song::GetFirstLine()
{
	return songFirstLine;
}

int Song::GetPlays()
{
	return numPlays;
}