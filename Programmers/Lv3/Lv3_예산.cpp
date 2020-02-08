#include <string>
#include <vector>
using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = -1;
	int sum = 0;
	int temp = 0;
	for (int i = 0; i < budgets.size(); i++) {
		if (answer < budgets[i])
			answer = budgets[i];
		sum += budgets[i];
	}
	temp = sum;
	while (temp > M) {
		temp = sum;
		answer--;
		for (int i = 0; i < budgets.size(); i++) {
			if (answer < budgets[i])
				temp -= budgets[i] - answer;
		}
	}

	return answer;
}
