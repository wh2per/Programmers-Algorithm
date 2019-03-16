#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void line4() {
	int N;
	cin >> N;
	vector<int> top(N, 0);

	for (int i = 0; i < N; i++)
		cin >> top[i];

	int answer = INT_MIN;
	int size = top.size();

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {		// 오른쪽 검사
			if (top[i] <= top[j]) {
				if (answer < j - i)
					answer = j - i;
				break;
			}
		}
	}
	for (int i = size - 1; i > 0; i--) {
		for (int j = i - 1; j >= 0; j--) {			// 왼쪽 검사
			if (top[i] <= top[j]) {
				if (answer < j - i)
					answer = i = j;
				break;
			}
		}
	}

	cout << answer;
}