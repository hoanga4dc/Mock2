#pragma once
#include<iostream>
#include<string>
#include"Playlist.cpp"
#include<vector>
#include<memory>
#include"DataProcess.cpp"
#include"Exist.cpp"
using namespace std;
class UI {
public:
	string Input_Code() {
		string temp;
		getline(cin, temp);
		return temp;
	}
	string Input_NewNamePlaylist() {
		cout << "nhap ten Playlist:";
		string s;
		getline(cin, s);
		Exist ex;
		if (ex.Exist_Playlist(s)) {
			return Input_NewNamePlaylist();
		}
		else return s;
	}
	string Input_ExistNamePlaylist() {
		cout << "nhap ten Playlist:";
		string s;
		getline(cin, s);
		Exist ex;
		if (ex.Exist_Playlist(s)) {
			return s;
		}
		else return Input_ExistNamePlaylist();
	}

	shared_ptr<Playlist> Input_Playlist() {
		shared_ptr<Playlist> p(new Playlist);
		p->set_name(Input_NewNamePlaylist());
		return p;
	}
	void Menu() {
		cout << "Tat ca Media file:         # press number 1" << endl;
		cout << "Danh sach cac playlist:    # press number 2" << endl;
	}
	void Menu_EditPlaylist() {
		cout << "Add mediafile:            #Add Number_of_mediafile\n";
		cout << "Delete mediafile:         #Del Number_of_mediafile\n";
		cout << "Back to list Playlist:    #Back\n";
	}
	void Menu_Playlist() {
		cout << "View information of Playlist:  #1\n";
		cout << "creat new Playlist:            #2\n";
		cout << "Edit Playlist:                 #3\n";
		cout << "Delete Playlist:               #4\n";
		cout << "Back to Menu:                  #5\n";
	}

};