#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int solution24(vector<vector<string>> clothes) {
	int answer = 0;
	map<string, int> m;

	for (int i = 0; i < clothes.size(); i++) {
		if (m.find(clothes[i][1]) != m.end()) 	//있을 떄
			m[clothes[i][1]]++;
		else									//없을 떄
			m.insert(make_pair(clothes[i][1], 1));
	}
	answer = 1;
	for (auto it = m.begin(); it != m.end(); it++)
		answer *= it->second + 1;

	return answer - 1;
}