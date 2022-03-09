#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int end = scoville.size();
	priority_queue <int, vector<int>, greater<int> > pq;
	for (int i = 0; i < scoville.size(); i++)
		pq.push(scoville[i]);
	if (pq.top() < K && end > 1) {
		do {
			int temp1 = pq.top();
			pq.pop();
			int temp2 = pq.top();
			pq.pop();
			int temp3 = temp1 + temp2 * 2;
			pq.push(temp3);
			answer++;
			end = pq.size();
		} while (pq.top() < K && end > 1);
	}

	if (pq.top() < K)
		answer = -1;
	return answer;
}