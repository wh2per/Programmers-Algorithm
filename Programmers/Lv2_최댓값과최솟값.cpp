#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string solution65(string s) {
	string answer = "";
	vector<int> v;
	stringstream split_string(s);
	string temp;

	while (split_string >> temp) 
		v.push_back(atoi(temp.c_str()));

	sort(v.begin(), v.end());
	answer += to_string(v[0]);
	answer += " ";
	answer += to_string(v[v.size()-1]);
	return answer;
}
