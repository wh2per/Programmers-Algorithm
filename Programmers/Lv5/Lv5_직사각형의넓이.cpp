#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

bool cmp_square(vector<int> v1, vector<int> v2) {		// y 시작점이 낮은 순 정렬
	if (v1[1] < v2[1])
		return true;
	else
		return false;
}

long long solution(vector<vector<int> > rectangles)
{
	long long answer = 0;

	//sort(rectangles.begin(), rectangles.end(), cmp_square);

	vector<vector<pair<int, int>>> v;
	
	for (int i = 0; i < rectangles.size(); ++i) {
		int x1 = rectangles[i][0];
		int x2 = rectangles[i][2];
		int y1 = rectangles[i][1];
		int y2 = rectangles[i][3];

		/*
		// y좌표마다의 벡터에 있는 x좌표 값들을 비교
		for (int j = y1; j < y2 - y1; ++j) {
			if(v[j].size()==0)		// 아무것도 없으면 바로 넣자
				v[j].push_back({ x1,x2 });
			else {
				// 겹치는 부분을 제외한 범위만 남기자 (시간초과 나면 이부분빼서 나중에 한번에 해버리자, 정렬도 하지말고)
				
			}
		}*/
		for (int j = y1; j < y2 - y1; ++j) 
			v[j].push_back({ x1,x2 });
	}

	int a = 1;

	return answer;
}

/*
int main() {
	cout << solution136({ { 1, 1, 6, 5 }, { 2, 0, 4, 2 }, {2, 4, 5, 7}, {4, 3, 8, 6}, {7, 5, 9, 7} });
	return 0;
}

*/