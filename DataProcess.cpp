#pragma once
#include<iostream>
#include<string>
#include<filesystem>
#include<fstream>
#include"Playlist.cpp"
#include<vector>
#include<memory>
using namespace std;
namespace fs = std::filesystem;
class DataProcess {
public:
	DataProcess(){}
	void  getlist_mediafile(string path, vector<string>& list) {

		for (auto entry : fs::directory_iterator(path))
		{

			if (entry.is_directory()) {//is folder
				//cout << entry.path().string() << endl;
				getlist_mediafile(entry.path().string(), list);

			}
			else {//is file
				//cout << "file:";
				//wcout << entry.path().c_str() << endl;
				string s = entry.path().filename().string();
				//string s = entry.path().filename().string();
				list.push_back(s);
			}
		}

	}
	//void get_ListPlayerlist() {
	//	ifstream ifs("D:/C++/test/ListPlaylist.txt");
	//	while (!ifs.eof()) {
	//		char temp[255];
	//		ifs.getline(temp, 255);
	//		string s1 = temp;
	//		cout << s1;
	//		cout << endl;
	//	}
	//}

	vector<shared_ptr<Playlist>> get_ListPlaylist() {
		ifstream ifs("D:/C++/test/ListPlaylist.txt");
		vector<shared_ptr<Playlist>> v;
		
		vector<string> v1;
		while (!ifs.eof()) {
			char temp[255];
			ifs.getline(temp, 255);
			string s = temp;

			if (s != "#") {
				v1.push_back(s);
			}
			else if (s == "#") {
				shared_ptr<Playlist> p(new Playlist);
				p->set_name(v1[0]);
				for (int i = 1; i < v1.size(); i++) {
					p->set_incdata(v1[i]);
				}
				v.push_back(p);
				v1.clear();
			}
		}
		return v;
	}
	void update_ListPlaylist(shared_ptr<Playlist> p) {
		vector<shared_ptr<Playlist>> v;
		v = get_ListPlaylist();
		if (v.size() == 0) { v.push_back(p); }
		int d = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i]->get_name() == p->get_name()) {
				v[i]->set_data(p->get_data());
				d++;
			}
		}
		if (d==0){ v.push_back(p); }
		ofstream ofs("D:/C++/test/ListPlaylist.txt", ostream::out);
		for (int i = 0; i < v.size(); i++) {
			ofs << v[i]->get_name() << endl;
			for (int j = 0; j < (v[i]->get_data().size()); j++) {
				ofs << (v[i]->get_data())[j] << endl;
			}
			ofs << "#" << endl;
		}

	}
	void Delete_Playlist(string s) {
		vector<shared_ptr<Playlist>> v;
		v = get_ListPlaylist();
		for (int i = 0; i < v.size(); i++) {
			if (v[i]->get_name() == s) {
				v.erase(v.begin() + i);
			}
		}
		ofstream ofs("D:/C++/test/ListPlaylist.txt", ostream::out);
		for (int i = 0; i < v.size(); i++) {
			ofs << v[i]->get_name() << endl;
			for (int j = 0; j < (v[i]->get_data().size()); j++) {
				ofs << (v[i]->get_data())[j] << endl;
			}
			ofs << "#" << endl;
		}
		cout << "Delete complete!\n";
		cout << "__________________\n";
	}

};