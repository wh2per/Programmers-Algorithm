#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int l, vector<int> v) {
	int answer;
	sort(v.begin(), v.end());
	answer = v[0] - 0;
	for (int i = 0; i < v.size() - 1; i++) {
		int temp = (v[i + 1] - v[i] + 1) / 2;
		if (answer < temp)
			answer = temp;
	}

	int temp = l - v[v.size() - 1];
	if (answer < temp)
		answer = temp;

	return answer;
}