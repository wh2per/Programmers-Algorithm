#include <string>
#include <vector>

using namespace std;

long long solution106(int n) {
	long long answer = 0;
	vector<long long> d(n+1,0);
	d[0] = 1;
	d[1] = 1;
	if (n > 1) {
		for (int i = 2; i <= n; i++)
			d[i] = (d[i - 1] + d[i - 2]) % 1234567;
	}
	return d[n];
}
