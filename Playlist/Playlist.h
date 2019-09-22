#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <vector>
#include <string>
#include<iostream>
#include "Song.h"
//#include "pch.h"
using namespace std;

class Playlist
{
	public:
		Playlist(string playlistInitName = "");
		string GetPlaylistName();
		vector<Song*> GetPlaylistSongs();
		void AddSong(Song* songToAdd);
		void RemoveSong(int songIndex);
		int PlaylistSize();


	private:
		vector<Song*> playlistVec;
		string playlistName;

};


#endif