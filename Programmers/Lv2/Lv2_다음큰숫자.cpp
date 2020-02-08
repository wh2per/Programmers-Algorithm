#include <string>
#include <vector>

using namespace std;

int countOne(int num) {
	int count = 0;
	while (num != 0) {
		if (num % 2 == 1)
			count++;
		num /= 2;
	}
	return count;
}

int solution(int n) {
	int answer = 0;
	int nc = countOne(n);
	int uc = 0;

	while (nc != uc) {
		uc = countOne(++n);
	}
	return n;
}
