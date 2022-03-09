#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
	long long answer = 0;
	vector<int> v;
	int ten = 1;
	while (n > 10) {
		v.push_back(n % 10);
		n /= 10;
	}
	v.push_back(n);
	sort(v.begin(), v.end(), less<int>());

	for (int i = 0; i < v.size(); i++) {
		answer += v[i] * ten;
		ten *= 10;
	}
	return answer;
}