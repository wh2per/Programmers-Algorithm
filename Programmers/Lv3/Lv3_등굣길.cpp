#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution84(int m, int n, vector<vector<int>> puddles) {
	int road[101][101] = { 0, };
	int check[101][101] = { 0, };

	for (int i = 0; i < puddles.size(); i++)			// ¹°Àº 0 
		check[puddles[i][1]][puddles[i][0]] = -1;

	road[1][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (check[i][j] == -1)						// ¹°
				road[i][j] = 0;
			else										// ¶¥
				road[i][j] = (road[i][j - 1] + road[i - 1][j]) % 1000000007;
		}
	}
	return road[n][m];
}
