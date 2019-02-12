#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int selectNext(vector<int> cost, vector<bool> check) {
	int end = 0; 
	int min = 500001;
	for (int i = 1; i < cost.size(); i++) {
		if (check[i] == false && cost[i] < min) {		// 비용이 가장 적은 지역을 탐색 
			min = cost[i];
			end = i;
		}
	}
	return end;
}

// 다익스트라 알고리즘 
int solution103(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	vector<map<int, int>> graph(N + 1);	// 비용 정보
	vector<int> cost(N + 1, 500001);		// 비용을 최대치로 초기화
	vector<bool> check(N + 1, false);
	cost[1] = 0;	// 1번은 0으로 초기화

	for (int i = 0; i < road.size(); i++) {		// 1-2, 2-1 두 개로 저장 
		if (graph[road[i][0]].find(road[i][1]) != graph[road[i][0]].end()) {		// 정보가 이미 있다면
			if (graph[road[i][0]][road[i][1]] > road[i][2]) {						// 더 적은 비용을 채택
				graph[road[i][0]][road[i][1]] = road[i][2];
				graph[road[i][1]][road[i][0]] = road[i][2];
			}
		}
		else {		// 정보가 없다면 신규 저장
			graph[road[i][0]].insert(make_pair(road[i][1], road[i][2]));
			graph[road[i][1]].insert(make_pair(road[i][0], road[i][2]));
		}
	}

	for (int i = 0; i < N - 1; i++) {		// N-1만큼 진행 (1번은 0으로 초기화 해뒀음)
		int end = selectNext(cost, check);			// 매번 비용이 가장 적은 지역을 다시 탐색
		for (auto j : graph[end]) {			// 비용이 가장 적은 지역과 연결된 지역들 순회
			if (check[j.first] == false)	// 아직 가보지 않은 곳이라면
				cost[j.first] = min(cost[j.first], cost[end] + j.second);		// 원래 값과 비교하여 저장
		}
		check[end] = true;
	}

	for (int i = 1; i < cost.size(); i++) {
		if (cost[i] <= K)
			answer++;
	}

	return answer;
}