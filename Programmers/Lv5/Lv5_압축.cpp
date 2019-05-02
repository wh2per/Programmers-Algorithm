#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution134(string msg) {
	vector<int> answer;
	map<string, int> dic;
	int num;
	for (num = 1; num <= 26; ++num) {
		char c = 'A' + num -1;
		string temp;
		temp = c;
		dic.insert({ temp ,num });
	}

	bool flag = true;
	for (int i = 0; i < msg.length(); ++i) {
		flag = true;
		string temp = "";
		string prev = "";
		while (flag) {
			temp += msg[i];
			if (dic.count(temp) > 0) { 		// 사전에 있음
				i++;
				prev = temp;
			}
			else {				// 사전에 없음
				flag = false;
				answer.push_back(dic[prev]);
				dic.insert({ temp, num });
				++num;
				--i;
			}
		}
	}
	return answer;
}