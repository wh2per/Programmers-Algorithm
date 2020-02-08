#include <string>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <limits>
using namespace std;

// 다익스트라 알고리즘보다 BFS가 훨씬 빠름.
// 가중치가 1일 때는 BFS를 이용하자!

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	int inf = 0;
	vector<list<int> > graph(n+1, list<int>());
	vector<int> dist(n+1, 0);
	vector<bool> check(n+1, false);
	queue<int> q;

	for (auto i = edge.begin(); i != edge.end(); i++) {		// 1-2, 2-1 두 개로 저장
		graph[(*i).front()].push_back((*i).back());
		graph[(*i).back()].push_back((*i).front());
	}

	q.push(1);
	check[1] = true;
	dist[1] = 0;

	while (!q.empty()) {
		int start = q.front(); 
		q.pop();
		for (auto i : graph[start]) {
			if (check[i]==false) {
				check[i] = true;
				dist[i] = dist[start] + 1;
				q.push(i);
			}
		}
	}

	sort(dist.begin(), dist.end());
	inf = dist.back();

	for (int i = 1; i <= n;  i++) {
		if (dist[i] == inf)
			answer++;
	}
	return answer;
}

