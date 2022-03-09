#include <vector>
#include <algorithm>
using namespace std;

//DP
int d[100001][4];

int solution(vector<vector<int> > land)
{
	int answer = 0;

	for (int i = 0; i < 4; i++)
		d[0][i] = land[0][i];

	for (int i = 1; i < land.size(); i++) {
		for (int j = 0; j < 4; j++) {		// 현재 줄 선택 
			for (int k = 0; k < 4; k++) {	// 다음 줄 선택
				if (k != j)
					d[i][j] = max(d[i][j], land[i][j] + d[i - 1][k]);
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		if (answer < d[land.size() - 1][i])
			answer = d[land.size() - 1][i];
	}
	return answer;
}

