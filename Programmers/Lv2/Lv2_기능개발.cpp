#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;

	for (int i = 0; i < progresses.size(); i++) {
		int temp = 100 - progresses[i];
		if (temp % speeds[i] != 0)
			temp = temp / speeds[i] + 1;
		else
			temp = temp / speeds[i];
		q.push(temp);
	}

	while (!q.empty()) {
		int temp1 = q.front();
		int temp2 = 1;
		q.pop();
		while (!q.empty() && q.front() <= temp1) {
			q.pop();
			temp2++;
		}
		answer.push_back(temp2);
	}
	return answer;
}