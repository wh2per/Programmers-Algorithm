#include <vector>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

const int dy[] = { 0,1,0,-1 };
const int dx[] = { 1,0,-1,0 };

struct info_tube {
	int y;
	int x;
	int dist;
};
long long d_tube[2501][51][51];

vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {
	vector<int> answer;
	for (int i = 0; i < 2501; i++) {
		for (int j = 0; j < 50; j++) {
			for (int k = 0; k < 50; k++) 
				d_tube[i][j][k] = INT_MAX;
		}
	}
	
	d_tube[0][0][0] = 0;
	queue<info_tube> q;
	q.push({ 0,0,0 });

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dist = q.front().dist;
		q.pop();
		if (dist > n*m)
			continue;
		if (d_tube[dist][y][x] > s)
			continue;
		for (int k = 0; k < 4; ++k) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			
			if (ny < 0 || ny >= m || nx < 0 || nx >= n || time_map[ny][nx]==-1)
				continue;
			if (d_tube[dist + 1][ny][nx] > d_tube[dist][y][x] + time_map[ny][nx]) {
				d_tube[dist + 1][ny][nx] = d_tube[dist][y][x] + time_map[ny][nx];
				q.push({ny,nx,dist+1});
			}
		}
	}
	for (int i = 0; i <= n * m; i++) {
		if (d_tube[i][m - 1][n - 1] > s) 
			continue;
		answer.push_back(i);
		answer.push_back(d_tube[i][m - 1][n - 1]);
		break;
	}

	return answer;
}