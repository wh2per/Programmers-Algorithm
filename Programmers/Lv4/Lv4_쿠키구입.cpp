#include <string>
#include <vector>
using namespace std;

int solution(vector<int> cookie) {
	int answer = 0;
	int size = cookie.size();
	vector<int> sum;		// 1 2 4 7 
	sum.push_back(0);
	sum.push_back(cookie[0]);
	for (int i = 1; i < size; i++)
		sum.push_back(sum[i] + cookie[i]);
	
	size = sum.size();

	int start_sum = 0;
	for (int start = 0; start < size; start++) {
		for (int end = size-1; end > start; end--) {
			int total = sum[end] - sum[start];
			if (total % 2 != 0)				// 쿠키가 홀수개이면 패스
				continue;
			if (total / 2 < answer)			// 나눠 가져도 이전 답보다 작을 경우 패스
				continue;
			for (int index = end; index > start; index-- ) {
				if (sum[index] - sum[start] == total / 2) {
					if (total / 2 > answer)
						answer = total / 2;
					break;
				}
				else if (sum[index] - sum[start] < total / 2)
					break;
			}
		}
	}

	return answer;
}
