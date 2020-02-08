#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int index = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			if (index % 2 == 1)
				s[i] = tolower(s[i]);
			else
				s[i] = toupper(s[i]);
			index++;
		}
		else
			index = 0;
	}

	return s;
}