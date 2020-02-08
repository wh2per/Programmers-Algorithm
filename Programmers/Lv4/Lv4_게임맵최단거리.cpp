#include <vector>
#include <queue>
using namespace std;

// BFS
int solution(vector<vector<int> > maps)
{
	int answer = 0;
	int ey = maps.size();
	int ex = maps[0].size();
	queue<pair<int, int>> q;		// (x,y) , 거리

	q.push(make_pair(0,0));		// 시작점 

	while (!q.empty()) {
		answer++;
		int size = q.size();
		for (int j = 0; j < size; j++) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			
			if (maps[y][x] == 0)
				continue;

			if (x == ex-1 && y == ey-1) 			// 도착
				return answer;

			maps[y][x] = 0;

			if (x + 1 < ex && maps[y][x + 1] == 1)
				q.push(make_pair(y, x + 1));

			if (x - 1 > -1 && maps[y][x - 1] == 1)  
				q.push(make_pair(y, x - 1));
			
			if (y + 1 < ey && maps[y + 1][x] == 1)
				q.push(make_pair(y + 1, x));
			
			if (y - 1 > -1 && maps[y - 1][x] == 1)  
				q.push(make_pair(y-1, x));
		}
		
	}
	return -1;
}
