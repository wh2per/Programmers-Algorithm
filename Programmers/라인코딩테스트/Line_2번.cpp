#include <iostream>
#include <string>
#include <queue>
using namespace std;

void line2() {
	string N;
	int i;
	string ans = "";

	cin >> N;
	queue<string> q;

	for (i = 0; !isdigit(N[i]); i++) {
		if (isupper(N[i])) {
			if (islower(N[i + 1]))
				q.push(N.substr(i, 2));
			else
				q.push(N.substr(i, 1));
		}
	}

	for (; i < N.size(); i++) {
		if (q.empty()) {
			ans = "error";
			break;
		}
		ans += q.front();
		q.pop();
		if (N[i] == '1') {
			if (i < N.size() - 1 && N[i + 1] == '0') {
				ans += "10";
				++i;
			}
			else
				ans += "";
		}
		else
			ans += N[i];
	}

	if (!q.empty())
		ans = "error";
	cout << ans;
}