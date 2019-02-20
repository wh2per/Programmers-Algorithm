#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

// DP 이용
// 맨 뒷자리부터 한글자씩 늘려가며 확인
int solution114(vector<string> strs, string t)
{
	int answer = 0;
	int size = t.length();
	set<string> s;
	vector<int> d(size+1, INT_MAX);

	for (string i : strs)		// set에 단어 조각을 삽입
		s.insert(i);

	d[size] = 0;

	for (int i = size-1; i >= 0; i--) {
		string temp="";
		for (int j = i; j < size; j++) {
			temp += t[j];
			if (s.count(temp) != 0) {		// 있으면
				if(d[j+1]!=INT_MAX)
					d[i] = min(d[i], d[j+1] + 1);
			}
			if (j > i + 5)
				break;
		}
	}
	if (d[0] != INT_MAX)
		answer = d[0];
	else
		answer = -1;

	return answer;
}
