#include <iostream>
using namespace std;

void line1() {
	int ans1 = 0;
	int ans2 = 0;
	long long i;
	long long N;
	cin >> N;
	for (i = 1; i*i < N; i++) {
		if (N%i == 0)
			ans1 = i;
	}
	if (i*i == N)
		ans1 = i;
	ans2 = N / ans1;
	cout << abs(ans2 - ans1);
}