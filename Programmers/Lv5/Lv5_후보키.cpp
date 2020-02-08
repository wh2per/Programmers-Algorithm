#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

bool hkey_able(vector<int> &answer, int now) {
	for (int i = 0; i < answer.size(); i++) {
		if ((answer[i] & now) == answer[i])
			return false;
	}
	return true;
}

bool cmp_hkey(pair<int, int> &p1, pair<int, int> &p2) {
	if (p1.second > p2.second)
		return true;
	else if (p1.second == p2.second) {
		if (p1.first < p2.first)
			return true;
		else
			return false;
	}
	else
		return false;
}

int solution(vector<vector<string>> relation) {
	vector<int> answer;
	int asize = relation.front().size();		// 속성의 갯수
	int rsize = relation.size();				// row 갯수

	vector<pair<int, int>> hkey;				// { 속성번호, 유니크 값 갯수 }

	for (int i = 0; i < asize; ++i) {
		set<string> s;
		for (int j = 0; j < rsize; ++j)
			s.insert(relation[j][i]);
		hkey.push_back({ i, s.size() });
	}
	sort(hkey.begin(), hkey.end(), cmp_hkey);			// 유니크 값 크기순 정렬

	for (int i = 1; i < (1 << asize); ++i) {
		int ukey = 1;

		for (int k = 0; k < asize; k++) {
			if (i&(1 << k))
				ukey *= hkey[k].second;
		}

		if (!hkey_able(answer, i) || ukey < rsize)			// 계산할 필요없다면
			continue;
		else {				// 정답이 될 수 있는지 확인
			set<string> ss;
			for (int j = 0; j < rsize; ++j) {
				string t = "";
				for (int k = 0; k < asize; k++) {
					if (i&(1 << k))
						t += relation[j][hkey[k].first];
				}
				ss.insert(t);
			}
			if (ss.size() == rsize)
				answer.push_back(i);
		}
	}

	return answer.size();
}