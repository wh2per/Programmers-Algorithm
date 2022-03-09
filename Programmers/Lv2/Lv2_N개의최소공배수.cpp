#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) {
	sort(arr.begin(), arr.end());
	int answer = arr[0];

	while (1) {
		int check = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (answer%arr[i] == 0)
				check++;
		}
		if (check == arr.size())
			break;
		else
			answer += arr[0];
	}
	return answer;
}