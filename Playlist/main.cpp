// Playlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Song.h"
#include "Playlist.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

// Function to get user selection
string UserSelection()
{
	string userSelection;
	cout << "Enter your selection now: ";
	getline(cin, userSelection);
	cout << endl;

	return userSelection;
}

//Contains string for options
void OptionMenu()
{
	cout << "add \t Adds a list of songs to the library" << endl
		<< "list \t Lists all the songs in the library" << endl
		<< "addp \t Adds a new playlist" << endl
		<< "addsp \t Adds a song to a playlist" << endl
		<< "listp \t Lists all the playlists" << endl
		<< "play \t Plays a playlist" << endl
		<< "delp \t Deletes a playlist" << endl
		<< "delsp \t Deletes a song from a playlist" << endl
		<< "delsl \t Deletes a song from the library (and all playlists)" << endl
		<< "options  Prints this options menu" << endl
		<< "quit \t Quits the program" << endl
		<< endl << endl;
}

//Prints all playlists in library
void PrintPlaylists(vector<Playlist*> playlistLibrary)
{
	for (unsigned int i = 0; i < playlistLibrary.size(); ++i)
	{
		cout << i << ": " << playlistLibrary.at(i)->GetPlaylistName()
			<< endl;
	}

	cout << endl;
}

int main()
{


	vector<Song*> songLibrary;				//Main vector of points pointing to songs in library
	vector<Playlist*> playlistLibrary;		//Main vector of playlists
	string userSelection;					
	string playlistName;					//Temp variable to initialize playlist
	string songName;						//Same as above, but for songs
	string songFirstLine;					//Same as above, but for first lines
	int playlistIndex;						//Index used for adding and deleting
	int songIndex;							//Same as above
	Song* addSong;							//Same as above
	Playlist* addPlaylist;					//Same as above
	vector<Song*> playPlaylistSongs;		//Temp vector of songs used when playing
	vector<Song*> delPlaylistSongs;			//Temp vector of songs used when deleting from library


	cout << "Welcome to the Firstline Player! Enter options to see menu options."
		<< endl;

	while (true)
	{
		userSelection = UserSelection();

		if (userSelection == "add")
		{

			cout << "Read in Song names and first lines (type \"STOP\" when done):"
				<< endl;
			while (true)
			{
				cout << "Song Name: ";
				getline(cin, songName);
				if (songName == "STOP")
				{
					break;
				}

				cout << endl << "Song's first line: ";
				getline(cin, songFirstLine);
				cout << endl;
				addSong = new Song(songName, songFirstLine);
				songLibrary.push_back(addSong);
			}



		}
		else if (userSelection == "list")
		{
			//Print out songs in needed format
			for (unsigned int i = 0; i < songLibrary.size(); ++i)
			{
				cout << songLibrary.at(i)->GetName() << ": \""
					<< songLibrary.at(i)->GetFirstLine() << "\", "
					<< songLibrary.at(i)->GetPlays() << " play(s)."
					<< endl;
			}

			cout << endl;
		}
		else if (userSelection == "addp")
		{
			//initialize and append playlist to playlist library
			cout << "Playlist name: ";
			getline(cin, playlistName);
			addPlaylist = new Playlist(playlistName);
			playlistLibrary.push_back(addPlaylist);

		}
		else if (userSelection == "addsp")
		{

			//Get playlist
			PrintPlaylists(playlistLibrary);
			cout << "Pick a playlist index number: ";
			cin >> playlistIndex;
			cin.ignore();
			cout << endl;

			//Print out available songs
			for (unsigned int i = 0; i < songLibrary.size(); ++i)
			{
				cout << i << ": " << songLibrary.at(i)->GetName() << endl;
			}

			//Get song index
			cout << "Pick a song index number: ";
			cin >> songIndex;
			cin.ignore();
			cout << endl;

			//Addsong to playlist library
			playlistLibrary.at(playlistIndex)->AddSong(songLibrary.at(songIndex));

		}
		else if (userSelection == "listp")
		{
			PrintPlaylists(playlistLibrary);
		}
		else if (userSelection == "play")
		{
			PrintPlaylists(playlistLibrary);
			cout << "Pick a playlist index number: ";
			cin >> playlistIndex;
			cin.ignore();

			playPlaylistSongs = playlistLibrary.at(playlistIndex)->GetPlaylistSongs();

			cout << endl << "Playing first lines of playlist: "
				<< playlistLibrary.at(playlistIndex)->GetPlaylistName() << endl;
			for (unsigned int i = 0; i < playPlaylistSongs.size(); ++i)
			{
				playPlaylistSongs.at(i)->PlaySong();
			}

			cout << endl;



		}
		else if (userSelection == "delp")
		{
			PrintPlaylists(playlistLibrary);
			cout << "Pick a playlist index number to delete: ";
			cin >> playlistIndex;
			cin.ignore();
			cout << endl;

			delete playlistLibrary.at(playlistIndex);
			playlistLibrary.erase(playlistLibrary.begin() + playlistIndex);
			
		}
		else if (userSelection == "delsp")
		{
			PrintPlaylists(playlistLibrary);
			cout << "Pick a playlist index number: ";
			cin >> playlistIndex;
			cin.ignore();
			cout << endl;

			playPlaylistSongs = playlistLibrary.at(playlistIndex)->GetPlaylistSongs();

			for (unsigned int i = 0; i < playPlaylistSongs.size(); ++i)
			{
				cout << i << ": " << playPlaylistSongs.at(i)->GetName() << endl;
			}

			cout << endl;

			cout << "Pick a song index number to delete: ";
			cin >> songIndex;
			cin.ignore();
			cout << endl;

			playlistLibrary.at(playlistIndex)->RemoveSong(songIndex);

		}
		else if (userSelection == "delsl")
		{
			for (unsigned int i = 0; i < songLibrary.size(); ++i)
			{
				cout << i << ": " << songLibrary.at(i)->GetName() << endl;
			}
			cout << "Pick a song index number: ";
			cin >> songIndex;
			cin.ignore();
			cout << endl;

			songName = songLibrary.at(songIndex)->GetName();

			for (unsigned int i = 0; i < playlistLibrary.size(); ++i)
			{
				delPlaylistSongs = playlistLibrary.at(i)->GetPlaylistSongs();
				
				for (unsigned int j = 0; j < delPlaylistSongs.size(); ++j)
				{
					if (songName == delPlaylistSongs.at(j)->GetName())
					{
						delPlaylistSongs.erase(delPlaylistSongs.begin() + j);
						playlistLibrary.at(i)->RemoveSong(j);
						--j;
					}
				}
			}

			delete songLibrary.at(songIndex);
			songLibrary.erase(songLibrary.begin() + songIndex);

		}
		else if (userSelection == "options")
		{
			OptionMenu();
		}
		else if (userSelection == "quit")
		{
			for (unsigned int i = 0; i < songLibrary.size(); ++i)
			{
				delete songLibrary.at(i);
			}
			break;
		}
		else
		{
			OptionMenu();
		}
	}


	cout << endl << "Goodbye!";

	return 0;
}