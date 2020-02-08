#include <string>
#include <vector>
#include <queue>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

// 프림 알고리즘 사용
struct cmp_cost {				// top에 가장 작은 수가 가도록 내림차순 정렬
	bool operator()(vector<int> t, vector<int> u) {
		return t[2] > u[2];
	}
};

bool isEnd(bool check[], int n) {
	for (int i = 0; i < n; i++) {
		if (check[i] == false)
			return false;
	}
	return true;
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	bool check[101] = { false, };
	int pos = 0;
	list<vector<int>> l;

	for (int i = 0; i < costs.size(); i++)
		l.push_back(costs[i]);
		
	check[(*l.begin())[0]] = true;		// 시작시점 설정
	
	while (!isEnd(check, n)) {
		priority_queue <vector<int>, vector<vector<int>>, cmp_cost > pq_island;
		for (int i = 0; i < n; i++) {
			if (check[i]) {		// 추가된 정점
				for (auto j : l) {		// 검사할 간선을 우선순위큐에 삽입
					if ((j[0] == i && check[j[1]]!=true) || (j[1] == i && check[j[0]]!=true))
						pq_island.push(j);
				}
			}
		}
		vector<int> v = pq_island.top();				// 비용이 가장 적은 간선을 선택
		answer += v[2];									// 비용에 추가
		check[v[0]] = true;								// 정점 추가
		check[v[1]] = true;								// 정점 추가
		l.erase(find(l.begin(), l.end(), v));
	}

	return answer;
}