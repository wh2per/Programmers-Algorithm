#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution6(vector<int> arr, int divisor) {
	vector<int> answer;

	if (divisor == 1) {
		for (int i = 0; i < arr.size(); i++) 
			answer.push_back(arr[i]);
	}
	else {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] % divisor == 0)
				answer.push_back(arr[i]);
		}
	}

	if (answer.size() == 0)
		answer.push_back(-1);
	else
		sort(answer.begin(), answer.end());

	return answer;
}