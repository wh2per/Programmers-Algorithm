#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// 브루트포스는 시간초과
// DP를 이용!
// m[i][j] = min(m[i][k] + m[k+1][j] + d[i-1]*d[k]*d[j])  (i<=k<j)
// m[i][j] = 0 (i==j)

int solution112(vector<vector<int>> matrix_sizes) {
	vector<vector<int>> m(matrix_sizes.size()+1,vector<int>(matrix_sizes.size()+1,0));
	vector<int> d;

	d.push_back(matrix_sizes[0][0]);
	for (int i = 0; i < matrix_sizes.size(); i++)
		d.push_back(matrix_sizes[i][1]);

	for (int diagonal = 0; diagonal < matrix_sizes.size(); diagonal++)
	{
		for (int i = 1; i + diagonal <= matrix_sizes.size(); i++)
		{
			int j = i + diagonal;
			if (j == i)
			{
				m[i][j] = 0;
				continue;
			}
			m[i][j] = INT_MAX;
			for (int k = i; k < j ; k++)
				m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j]);
		}
	}

	return m[1][matrix_sizes.size()];
}


// 다른 사람풀이
//int solution(vector<vector<int>> matrix_sizes){
//	vector<vector<int> > d;
//	int answer = 0, s = matrix_sizes.size();
//	d.resize(s, vector<int>(s, 0));
//	for (int i = s - 1; i >= 0; i--) for (int j = i + 1; j < s; j++) {
//		d[i][j] = INT_MAX;
//		for (int k = i; k < j; k++)
//			d[i][j] = min(d[i][j], d[i][k] + d[k + 1][j] + matrix_sizes[i][0] * matrix_sizes[k][1] * matrix_sizes[j][1]);
//	}
//	return d[0][s - 1];
//}