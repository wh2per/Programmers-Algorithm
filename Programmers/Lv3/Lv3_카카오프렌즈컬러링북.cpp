#include <vector>
using namespace std;

vector<vector<int>> paper;

int flood_fill(int color, int i, int j, int m, int n) {
	int dx[] = { 0,0,-1,1 };
	int dy[] = { 1,-1,0,0 };

	if (i < 0 || j < 0 || i >= m || j >= n || color != paper[i][j])
		return 0;
	
	int size = 1;
	paper[i][j] = 0;			// 계산한 부분은 0으로 변경

	for (int k = 0; k < 4; k++) 
		size += flood_fill(color, i + dx[k], j + dy[k], m, n);

	return size;
}

// flood_fill 알고리즘 사용!
vector<int> solution93(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	paper = picture;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (paper[i][j] != 0) {
				int size = flood_fill(paper[i][j], i, j, m, n);
				if (max_size_of_one_area < size)
					max_size_of_one_area = size;
				number_of_area++;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}
