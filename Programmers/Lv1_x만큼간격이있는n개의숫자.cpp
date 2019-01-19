#include <string>
#include <vector>

using namespace std;

vector<long long> solution3(int x, int n) {
	vector<long long> answer;
	long long temp = 0;
	for (int i = 0; i < n; i++) {
		temp += x;
		answer.push_back(temp);
	}
	return answer;
}