#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	stack<int> s;
	int size = heights.size();
	int index = heights.size();
	int j = 0;

	for (int i = size - 1; i >= 1; i--) {
		int temp = heights[i];
		for (j = i - 1; j >= 0; j--) {
			if (temp < heights[j]) {
				s.push(j + 1);
				break;
			}
		}
		if (j == -1)
			s.push(0);
	}
	s.push(0);
	while (!s.empty()) {
		answer.push_back(s.top());
		s.pop();
	}

	return answer;
}