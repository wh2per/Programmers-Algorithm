#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int> pq;

	int start = 0;
	while (stock < k) {
		for (int i = start; i < dates.size(); i++) {
			if (dates[i] <= stock) {		// 안받아도 그만
				pq.push(supplies[i]);
			}
			else {				// 받아야하면
				start = i;		// 그날짜로 가서
				break;
			}
		}
		answer++;		//받고
		stock += pq.top();
		pq.pop();
	}

	return answer;
}