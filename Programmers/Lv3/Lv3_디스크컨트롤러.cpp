#include <string>
#include <vector>
#include <queue>
using namespace std;

struct cmp1 {				// top에 가장 작은 수가 가도록 내림차순 정렬
	bool operator()(vector<int> t, vector<int> u) {
		return t[1] > u[1];
	}
};

struct cmp2 {				// top에 가장 작은 수가 가도록 내림차순 정렬
	bool operator()(vector<int> t, vector<int> u) {
		return t[0] > u[0];
	}
};

// SRF 스케줄링을 구현
int solution76(vector<vector<int>> jobs) {
	int answer = 0;
	priority_queue <vector<int>, vector<vector<int>>, cmp1 > pq_len;
	priority_queue <vector<int>, vector<vector<int>>, cmp2 > pq_arrive;
	
	for (int i = 0; i < jobs.size(); i++)
		pq_arrive.push(jobs[i]);

	int time = pq_arrive.top()[0];
	pq_len.push(pq_arrive.top());
	pq_arrive.pop();

	while (!pq_len.empty() || !pq_arrive.empty()) {
		if (!pq_arrive.empty() && time >= pq_arrive.top()[0]) {
			pq_len.push(pq_arrive.top());
			pq_arrive.pop();
		}
		else if(!pq_len.empty()){
			int arrive = pq_len.top()[0];
			int len = pq_len.top()[1];
			answer += len;						// 실행시간
			if (time < arrive)
			pq_len.pop();
		}
		else {
			time = pq_arrive.top()[0];
		}
	}
	return answer/jobs.size();
}

