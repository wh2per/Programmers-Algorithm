#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int solution85(vector<int> left, vector<int> right) {
	int answer = 0;
	int size = left.size();
	vector<vector<int>> d(size + 1, vector<int>(size + 1, 0));		// 0으로 초기화

	for (int i = 0; i <= size; i++) 
		d[0][i] = -1;

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]);
			if (d[i][j - 1] != -1 && left[i - 1] > right[j - 1]) 
				d[i][j] = d[i][j - 1] + right[j - 1];
		}
	}

	return answer = d[size][size];
}