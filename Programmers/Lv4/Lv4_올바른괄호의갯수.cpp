#include <string>
#include <vector>
using namespace std;

// 카탈란 수 -> Cn = C0*Cn-1 + C1*Cn-2 + C2*Cn-3 + ... + Cn-1C0
int solution117(int n) {
	int answer = 0;
	vector<int> d;
	d.push_back(1); //C0 = 1;
	d.push_back(1); //C1 = 1;

	for (int i = 2; i <= n; i++) {
		int sum = 0;
		for (int j = 0; j < i; j++) {
			int k = i - j - 1;
			sum += d[j] * d[k];
		}
		d.push_back(sum);
	}
	return d[n];
}

