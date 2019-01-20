#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string solution69(string s) {
	bool check = true;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			if (check) {
				s[i] = toupper(s[i]);
				check = false;
			}
			else
				s[i] = tolower(s[i]);
		}
		else
			check = true;
	}
	return s;
}