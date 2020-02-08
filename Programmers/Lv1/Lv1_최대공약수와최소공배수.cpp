#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
	vector<int> answer;
	int max = 1;
	int min = m;
	for (int i = 1; i <= n; i++) {
		if (n%i == 0 && m%i == 0)
			max = i;
	}
	
	for (int i = n; i <= n * m; i += n) {
		if (i%n == 0 && i%m == 0) {
			min = i;
			break;
		}
	}
	answer.push_back(max);
	answer.push_back(min);
	return answer;
}