#include <string>
#include <vector>

using namespace std;

int solution78(int n) {
	int d[60001];
	d[1] = 1;
	d[2] = 2;
	if (n > 2) {
		for (int i = 3; i <= n; i++)
			d[i] = (d[i - 1] + d[i - 2]) % 1000000007;
	}
	return d[n];
}