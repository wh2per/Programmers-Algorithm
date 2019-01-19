#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution37(string s) {
	string answer = "";
	vector<char> v;
	for (int i = 0; i < s.length(); i++)
		v.push_back(s[i]);
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < s.length(); i++)
		answer.push_back(v[i]);
	return answer;
}