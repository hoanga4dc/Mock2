#pragma once
#include<string>
#include<vector>
#include<iostream>
using namespace std;
using namespace std;
class Playlist {
private:
	string name;
	vector<string> data;
public:
	Playlist() {}
	void set_name(string s) {
		this->name = s;
	}
	void set_data(vector<string> v) {
		this->data = v;
	}
	void set_incdata(string t) {
		data.push_back(t);
	}
	void set_decdata(int d) {
		data.erase(data.begin() + d);
	}
	string get_name() {
		return name;
	}
	vector<string> get_data() {
		return data;
	}
	void Display() {
		cout << "Name: "<<name << endl;
		cout << "Mediafiles:\n";
		for (int i = 0; i < data.size(); i++) {
			cout << " "<<i + 1 << ". " << data[i] << endl;
		}
		cout << "___________________\n";
	}
};
