#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct cmp {				// top에 가장 작은 수가 가도록 내림차순 정렬
	bool operator()(vector<int> t, vector<int> u) {
		return t[0] > u[0];
	}
};

int solution(vector<vector<int>> routes) {
	int answer = 1;
	vector<vector<int>> camera;
	priority_queue <vector<int>, vector<vector<int>>, cmp> pq;
	
	for (int i = 0; i < routes.size(); i++) 
		pq.push(routes[i]);
	
	vector<int> prev = pq.top();
	pq.pop();
	camera.push_back(prev);

	while (!pq.empty()) {
		vector<int> now = pq.top();
		pq.pop();
		if (prev[1] >= now[0]) {		// prev.end >= now.start
			if (camera[answer - 1][1] >= now[0]) {		// 기존 카메라로 찍을 수 있을 때
				camera[answer - 1][0] = now[0];
				camera[answer - 1][1] = min(camera[answer - 1][1], now[1]);
			}
			else {									// 기존 카메라로 찍을 수 없을 때
				camera.push_back(now);
				answer++;
			}
		}	
		else {							// prev.end < now.start
			camera.push_back(now);
			answer++;
		}
		prev = now;
	}
	return answer;
}

