#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void line5() {
	queue<int> q;
	int min = 0;
	int max = 200001;

	int cony, brown;
	cin >> cony;
	cin >> brown;

	int n = 1;
	while (cony + (n * (n + 1) / 2) <= max)
		n++;

	vector<int> cony_pos(n);
	vector<bool> check(max);
	vector<int> brown_pos(max);

	cony_pos[0] = cony;
	for (int i = 1; i < n; i++)
		cony_pos[i] = cony_pos[i - 1] + i;

	check[brown] = true;
	brown_pos[brown] = 0;
	q.push(brown);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now - 1 >= min) {
			if (check[now - 1] == false) {
				q.push(now - 1);
				check[now - 1] = true;
				brown_pos[now - 1] = brown_pos[now] + 1;
			}
		}

		if (now + 1 <= max) {
			if (check[now + 1] == false) {
				q.push(now + 1);
				check[now + 1] = true;
				brown_pos[now + 1] = brown_pos[now] + 1;
			}
		}

		if (now * 2 <= max) {
			if (check[now * 2] == false) {
				q.push(now * 2);
				check[now * 2] = true;
				brown_pos[now * 2] = brown_pos[now] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (brown_pos[cony_pos[i]] == i) {
			cout << brown_pos[cony_pos[i]];
			return;
		}
	}
	cout << -1;
}
