#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool remove_rock(vector<int> &rocks, int min, int n) {
	int prev = 0;
	int remove = 0;
	for (int r : rocks) {
		if (r - prev > min)
			prev = r;
		else
			remove++;
	}
	if (remove > n)
		return true;
	else
		return false;
}

// 파라메트릭 서치 이용!
int solution(int distance, vector<int> rocks, int n) {
	sort(rocks.begin(), rocks.end());
	int low = 0;
	int mid = 0;
	int high = distance;

	while (low <= high) {
		mid = (low + high) / 2;	
		if (remove_rock(rocks, mid, n))		// 돌을 n보다 많이 제거 했다면
			high = mid - 1;					// high를 줄이고
		else								// 돌을 n보다 적게 제거 했다면
			low = mid + 1;					// low를 올리자
	}
	return low;
}

