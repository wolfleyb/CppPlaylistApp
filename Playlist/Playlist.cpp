#include <vector>
#include <string>
#include<iostream>
#include "Song.h"
#include "pch.h"
#include "Playlist.h"
using namespace std;

Playlist::Playlist(string playlistInitName)
{
	vector<Song*> playlistInitVec = {};
	playlistVec = playlistInitVec;
	playlistName = playlistInitName;
}

string Playlist::GetPlaylistName()
{
	return this->playlistName;
}

vector<Song*> Playlist::GetPlaylistSongs()
{
	return this->playlistVec;
}

void Playlist::AddSong(Song* songToAdd)
{
	this->playlistVec.push_back(songToAdd);
}

void Playlist::RemoveSong(int songIndex)
{
	this->playlistVec.erase(playlistVec.begin() + songIndex);
}

int Playlist::PlaylistSize()
{
	return playlistVec.size();
}
