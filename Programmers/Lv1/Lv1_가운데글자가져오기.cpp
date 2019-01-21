#include <string>
#include <vector>

using namespace std;

string solution4(string s) {
	string answer = "";
	if (s.length() % 2 == 0)
		answer.push_back(s[(s.length() / 2) - 1]);
	answer.push_back(s[s.length() / 2]);
	return answer;
}
