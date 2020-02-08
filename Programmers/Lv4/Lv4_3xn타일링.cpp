#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
	vector<long long> d(n + 1, 0);
	d[0] = 1;
	for (int i = 2; i <= n; i += 2) {
		d[i] = d[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2) {
			d[i] += d[j] * 2;
		}
		d[i] = d[i] % 1000000007;
	}
	return d[n];
}
