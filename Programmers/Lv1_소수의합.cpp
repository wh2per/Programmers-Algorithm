#include <vector>
using namespace std;


long long solution8(int N) {
	long long answer = 0;
	const long long MAX = 10000000;
	vector<bool> check(MAX + 1);
	check[0] = check[1] = true;

	for (int i = 2; i*i <= N; i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= N; j += i)
				check[j] = true;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (check[i] == false) {
			answer += i;
		}
	}

	return answer;
}