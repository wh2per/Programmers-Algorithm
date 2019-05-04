#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp_fail(pair<double, int> p1, pair<double, int> p2){
	if (p1.first < p2.first)
		return true;
	else if (p1.first == p2.first) {
		if (p1.second < p2.second)
			return true;
		else
			return false;
	}
	else
		return false;
}

vector<int> solution136(int N, vector<int> stages) {
	vector<int> answer;
	vector<int> success(N);
	vector<int> fail(N);
	vector<pair<double, int>> ans;

	for (int i = 0; i < stages.size(); ++i) {
		if (stages[i] > N) {		// 다깬사람
			for (int j = 0; j < N; j++)
				++success[j];
		}
		else {			// 다 못깬사람
			for (int j = 0; j < stages[i]; ++j)
				++success[j];
			++fail[stages[i] - 1];
		}
	}

	for (int i = 0; i < N; ++i) 
		ans.push_back({(double)success[i] / fail[i], i + 1});		// 0으로 나누기를 방지하기 위해 거꾸로 나누고 정렬을 반대로
	stable_sort(ans.begin(), ans.end(), cmp_fail);			// 기존 정렬한것을 그대로 유지하기 위해

	for (int i = 0; i < N; i++) 
		answer.push_back(ans[i].second);
	return answer;
}