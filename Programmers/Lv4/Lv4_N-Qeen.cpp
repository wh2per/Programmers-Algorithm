#include <string>
#include <vector>

using namespace std;

vector<vector<bool>> arr(13,vector<bool>(13,false));
vector<bool> check_col(13, false);
vector<bool> check_dig(26, false);
vector<bool> check_dig2(26, false);

bool check(int row, int col,int n) {
	// |
	if (check_col[col]) {
		return false;
	}
	// 왼쪽 위 대각선
	if (check_dig[row + col]) {
		return false;
	}
	// /
	if (check_dig2[row - col + n]) {
		return false;
	}
	return true;
}

int calc(int n, int row) {
	if (row == n) {
		// ans += 1;
		return 1;
	}
	int cnt = 0;
	for (int col = 0; col < n; col++) {
		if (check(row, col, n)) {
			check_dig[row + col] = true;
			check_dig2[row - col + n] = true;
			check_col[col] = true;
			arr[row][col] = true;
			cnt += calc(n,row + 1);
			check_dig[row + col] = false;
			check_dig2[row - col + n] = false;
			check_col[col] = false;
			arr[row][col] = false;
		}
	}
	return cnt;
}

int solution111(int n) {
	int answer = calc(n,0);

	return answer;
}