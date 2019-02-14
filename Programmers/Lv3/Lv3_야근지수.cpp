#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct work_cmp {				// top에 가장 높은 수가 가도록 정렬
	bool operator()(int t, int u) {
		return t < u;
	}
};

long long solution107(int n, vector<int> works) {
	long long answer = 0;
	priority_queue <int, vector<int>, work_cmp > pq;
	for (auto i : works)
		pq.push(i);

	for (int i = 0; i < n; i++) {
		int a = pq.top();
		pq.pop();
		if (a == 0)
			pq.push(0);
		else
			pq.push(a - 1);
	}

	while (!pq.empty()) {
		answer += pq.top()*pq.top();
		pq.pop();
	}
	return answer;
}
