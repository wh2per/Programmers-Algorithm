#include <string>
#include <vector>
#include <list>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - lost.size();
	list<int> l(begin(reserve), end(reserve));

	for (int i = 0; i < lost.size(); i++) {
		auto it = l.begin();
		for (int j = 0; j < l.size(); j++) {
			if (abs(lost[i] - *it) <= 1) {
				answer++;
				l.erase(it);
				break;
			}
			it++;
		}
	}
	return answer;
}
