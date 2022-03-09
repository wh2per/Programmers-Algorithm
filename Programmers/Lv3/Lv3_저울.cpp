#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> weight) {
	int answer = 1;
	sort(weight.begin(), weight.end());
	
	for (int i = 0; i < weight.size(); i++) {
		if (answer < weight[i])				// 누적합보다 작으면 탈출
			break;
		answer += weight[i];			// 누적합
	}
	 
	return answer;
}
