#include <string>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

int solution100(string dirs)
{
	int answer = 0;
	pair<int, int> start = make_pair(0, 0);
	set<vector<pair<int,int>>> s;		// 이미 갔던 길인지
	
	for (int i = 0; i < dirs.length(); i++) {
		vector<pair<int, int>> pos;
		vector<pair<int, int>> pos2;
		pair<int, int> temp = start;
		pos.push_back(start);
		if (dirs[i] == 'L') {
			if (start.first > -5) {
				start.first--;
				pos.push_back(make_pair(start.first,start.second));
				s.insert(pos);
				pos2.push_back(start);
				pos2.push_back(temp);
				s.insert(pos2);
			}
		}
		else if (dirs[i] == 'R') {
			if (start.first < 5) {
				start.first++;
				pos.push_back(make_pair(start.first, start.second));
				s.insert(pos);
				pos2.push_back(start);
				pos2.push_back(temp);
				s.insert(pos2);
			}
		}
		else if (dirs[i] == 'U') {
			if (start.second < 5) {
				start.second++;
				pos.push_back(make_pair(start.first, start.second));
				s.insert(pos);
				pos2.push_back(start);
				pos2.push_back(temp);
				s.insert(pos2);
			}
		}
		else if (dirs[i] == 'D') {
			if (start.second > -5) {
				start.second--;
				pos.push_back(make_pair(start.first, start.second));
				s.insert(pos);
				pos2.push_back(start);
				pos2.push_back(temp);
				s.insert(pos2);
			}
		}
	}

	return s.size()/2;
}
