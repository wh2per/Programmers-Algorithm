#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// BFS가 DFS보다 탐색 횟수가 더 많음
// DP가 가장 빠름

int solution124(int tK, vector<vector<int>> travel) {
	vector<int> d(100003);
	int tsize = travel.size();
	
	for (int i = 0; i < tsize; i++) {
		for (int j = tK; j >= 0; j--) {
			d[j] = INT_MIN;
			if (j >= travel[i][0])
				d[j] = max(d[j], d[j - travel[i][0]] + travel[i][1]);
			if (j >= travel[i][2])
				d[j] = max(d[j], d[j - travel[i][2]] + travel[i][3]);
		}
	}
	return d[tK];
}

