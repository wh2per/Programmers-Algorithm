#include <map>
using namespace std;

map<pair<int, int>, int> dm;

int dfs(int plusCount, int n) {
	if (plusCount > 38)		// *은 19개가 최대! 따라서 +는 38개가 최대
		return 0;

	if (n == 1) {			// 구하려는 수가 1일 때
		if (plusCount == 0)	// 남은 plus가 0개
			return 1;
		else
			return 0;
	}

	if (dm.find({ plusCount,n }) != dm.end())		// 이미 구한 값이 있으면 가져온다
		return dm[{ plusCount, n }];

	dm[{ plusCount, n }] = dfs95(plusCount + 1, n - 1);		// +를 추가!

	if (plusCount >= 2 && n % 3 == 0)		// plusCount를 2개 모았고, 구하려는 수가 3의 배수일 때
		dm[{ plusCount, n }] += dfs95(plusCount - 2, n / 3);		// 방법의 수를 추가!

	return dm[{ plusCount, n }];
}

int solution(int n) {
	int answer = dfs95(0, n);
	return answer;
}