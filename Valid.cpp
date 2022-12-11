#pragma once
#include<string>
using namespace std;
class Valid {
public:
	bool CheckNumber(string s) {
		for (int i = 0; i < s.size(); i++) {
			if ((int(s[i]) < 48) || (int(s[i]) > 57)) {
				return false;
			}
		}
		return true;
	}
};