#include <vector>
#include <algorithm>
using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution97(int m, int n, vector<vector<int>> city_map) {
	vector<vector<int>> road(m+1,vector<int>(n+1,0));
	vector<vector<int>> check(m + 1, vector<int>(n + 1, 0));
	
	road[1][0] = 1;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			check[i][j] = city_map[i - 1][j - 1];
			if (check[i][j] == 1) 		// 못감
				road[i][j] = 0;
			else if (check[i][j] == 2) {		// 보행자 우선
				road[i][j] = max(road[i][j-1], road[i-1][j]);	// 위쪽과 왼쪽 중 큰것을 채택
			}
			else {										// 그냥 길
				if (check[i][j-1] == 2 && check[i - 1][j] == 2) {				// 왼쪽과 위쪽 둘다 2
					int ti1 = i;					// 왼쪽 찾기
					int tj1 = j-1;
					while (check[ti1][tj1] == 2)
						tj1--;
					int ti2 = i-1;					// 위쪽 찾기
					int tj2 = j;
					while (check[ti2][tj2] == 2)
						ti2--;
					road[i][j] = (road[ti1][tj1]+road[ti2][tj2]) % MOD;
				}
				else if (check[i][j - 1] == 2) {			// 왼쪽만 2
					int ti = i;
					int tj = j-1;
					while (check[ti][tj] == 2)
						tj--;
					road[i][j] = (road[i - 1][j] + road[ti][tj]) % MOD;
				}
				else if (check[i - 1][j] == 2) {			// 위쪽만 2
					int ti = i-1;
					int tj = j;
					while (check[ti][tj] == 2)
						ti--;
					road[i][j] = (road[i][j-1] + road[ti][tj]) % MOD;
				}
				else {										 // 둘 다 2가 아님
					road[i][j] = (road[i][j - 1] + road[i - 1][j])%MOD;
				}
			}
		}
	}

	return road[m][n];
}