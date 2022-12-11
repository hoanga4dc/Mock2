#pragma once
#include"DataProcess.cpp"
#include"UI.cpp"
#include<memory>
#include"Valid.cpp"
#include<sstream>
class Controller {
private:
	DataProcess DP;
	UI u;
	Valid Valid;
public:

	void Edit_Playlist(shared_ptr<Playlist> v,int &d) {
		string s = u.Input_Code();
		cout << s.size() << endl;
		if (s == "Back") { d++; DP.update_ListPlaylist(v); }
		else {
			string temp; 
			string number;
			
			for (int i = 0; i < 3; i++) { temp += s[i]; }
			for (int i = 3; i < s.size(); i++) { number += s[i]; }
			if (Valid.CheckNumber(number)) {
				int x;
				vector<string> list_mediafiles;
				string path = "D:\\Music";
				DP.getlist_mediafile(path, list_mediafiles);
				stringstream s2n(number);
				s2n >> x;
				if (temp == "Add"&&x>0&&x<=list_mediafiles.size()) {
					v->set_incdata(list_mediafiles[x-1]);

				}
				else if (temp == "Del" && x > 0 && x < v->get_data().size() + 1) {
					v->set_decdata(x - 1);
				}

			}
		}
	}
	void Run() {
		vector<string> v;
		string path="D:\\Music";
		DP.getlist_mediafile(path, v);
		while (true) {
			u.Menu();
			int k;
			cin >> k;
			switch (k) {
			case 1: {
				system("cls"); 
				for (int i = 0; i < v.size(); i++) {
						cout << v[i] << endl;
						}
				}
				  cout << "_____________________\n";
				  break;
			case 2: {
				system("cls");
				vector <shared_ptr<Playlist>> v2;
				
				int d_exit2 = 0;
				while (d_exit2 == 0) {
					v2 = DP.get_ListPlaylist();
					for (int i = 0; i < v2.size(); i++) {
						cout << i + 1 << "." << v2[i]->get_name() << endl;
					}
					u.Menu_Playlist();
					int k1;
					cin >> k1;
					cin.ignore();
					switch (k1) {
					case 1: {
						system("cls");
						for (int i = 0; i < v2.size(); i++) {
							cout << i + 1 << "." << v2[i]->get_name() << endl;
						}
						cout << "choose one:";
						int d;
						cin >> d;
						cout << "_________________\n";
						v2[d - 1]->Display();
						break;
					}
					case 2: {
						system("cls");
						DP.update_ListPlaylist(u.Input_Playlist());
						break;
					}
					case 3: {
						system("cls");
						for (int i = 0; i < v2.size(); i++) {
							cout << i + 1 << "." << v2[i]->get_name() << endl;
						}
						cout << "choose one Playlist to Edit:";
						int d;
						cin >> d;
						cin.ignore();
						int k2 = 0;
						while (k2 == 0) {
							system("cls");
						cout << "\nTHONG TIN PLAYLIST:\n";
						v2[d - 1]->Display();
						for (int i = 0; i < v.size(); i++) {
							cout <<i+1<<"."<< v[i] << endl;
						}
						u.Menu_EditPlaylist();					
							Edit_Playlist(v2[d - 1], k2);
							}
						break;
					}
					case 4: {
						system("cls");
						string temp = u.Input_ExistNamePlaylist();
						DP.Delete_Playlist(temp);
						break;
					}
					case 5: {
						system("cls");
						d_exit2++;
						break;
					}
					}
				}
				break;
			}
			}
			
		}
	}

};