#pragma once
#include"DataProcess.cpp"
#include<vector>
#include<memory>
#include<string>
class Exist {
public:
	Exist(){}
	bool Exist_Playlist(string s) {
		vector<shared_ptr<Playlist>> v;
		DataProcess DP;
		v = DP.get_ListPlaylist();
		for (int i = 0; i < v.size(); i++) {
			if (v[i]->get_name() == s) {
				return true;
			}
		}
		return false; 
	}
};