#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int cweight = 0;
	int ctime = 0;
	queue<pair<int, int> > q;
	answer++;
	cweight += truck_weights[0];
	q.push(make_pair(1, truck_weights[0]));
	for (int i = 1; i < truck_weights.size(); i++) {
		answer++;
		ctime = q.front().first;
		if (answer - ctime == bridge_length) {
			cweight -= q.front().second;
			q.pop();
		}

		if (cweight + truck_weights[i] <= weight) {
			cweight += truck_weights[i];
			q.push(make_pair(answer, truck_weights[i]));
		}
		else {
			i--;
		}

	}

	while (!q.empty()) {
		answer++;
		ctime = q.front().first;
		if (answer - ctime == bridge_length) {
			cweight -= q.front().second;
			q.pop();
		}
	}

	return answer;
}