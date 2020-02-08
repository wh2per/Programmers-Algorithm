#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> food_times, long long k) {
	queue<pair<int, int>> q;
	for (int i = 0; i < food_times.size(); ++i)
		q.push({ i + 1,food_times[i] });

	while (q.size() != 0 && k > 0) {		// 남은 음식이 없거나, 시간이 다했을경우 탈출
		long long _size = q.size();
		long long sub = k / _size;
		k %= _size;

		if (sub == 0)		// 더 이상 한번에 뺄수 없으면 탈출
			break;

		long long rest = 0;
		for (int i = 0; i < _size; ++i) {
			pair<int, int> a = q.front();
			q.pop();
			a.second -= sub;
			if (a.second <= 0) 		// 음식을 다먹었다면
				rest -= a.second;	// 초과된 시간만큼 저장해두고
			else
				q.push(a);
		}
		k += rest;
	}

	if (q.empty())	// 남은 음식이 없으면	
		return -1;
	else {				// 음식이 있을 때
		if (k > 0) {	// 시간이 남았을 때
			while(!q.empty()) {
				--k;
				if (k == -1)
					return q.front().first;
				q.pop();
			}
			//return -1;
		}
		else 		// 시간이 끝났을 때
			return q.front().first;
	}
}

