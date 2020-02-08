#include <string>
#include <vector>

using namespace std;

long long get_num(long long target) {		// 자신을 제외한 최대 약수를 반환
	long long i;
	for (i = 2; i*i < target; i++) {
		if (target%i==0)
			break;
	}
	if (i*i > target)
		return 1;
	return target / i;
}

// 각 자리는 최대 약수가 들어감
vector<int> solution(long long begin, long long end) {
	vector<int> answer;
	long long start_block = 1;
	long long end_block = end >> 1;

	if (begin == 1) {
		answer.push_back(0);
		begin++;
	}

	for (long long i = begin; i <= end; i++) {
		answer.push_back(get_num(i));
	}

	return answer;
}
