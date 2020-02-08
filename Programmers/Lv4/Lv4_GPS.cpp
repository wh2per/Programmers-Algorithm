#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
	int answer = 10001;
	vector<vector<int>> gps_dp(n + 1,vector<int>(n + 1,10001));			// i->j 가는 동안 최소 수정값
	vector<vector<int>> gps_graph(n+1);
	
	for (auto a : edge_list) {
		gps_graph[a[0]].push_back(a[1]);
		gps_graph[a[1]].push_back(a[0]);
	}

	gps_dp[0][gps_log[0]] = 0;
	for (int i = 1; i < k - 1; ++i){		// 시간대별 택시 위치	(마지막 제외)
		for (int j = 1; j <= n; ++j){		// 노드 전부 검사
			int diff = 0;
			if (gps_log[i] != j)		// 수정해야할 부분일 경우!
				diff = 1;
			gps_dp[i][j] = min(gps_dp[i][j], gps_dp[i - 1][j] + diff);		// 현재 자리에 가만히 있는 경우
			for (auto a : gps_graph[j])										// 현재 자리에 연결된 지점으로 가는 경우
				gps_dp[i][j] = min(gps_dp[i][j],gps_dp[i - 1][a] + diff);
		}
	}

	for (auto a : gps_graph[gps_log.back()]) 			// 마지막 도착지점 검사
		answer = min(answer, gps_dp[gps_log.size() - 2][a]);

	if (answer == 10001)
		return -1;
	else
		return answer;
}