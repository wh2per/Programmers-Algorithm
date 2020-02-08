#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
	bool answer = true;
	int num = x;
	int sum = 0;

	while (num > 10) {
		sum += num % 10;
		num /= 10;
	}
	sum += num;

	if (x%sum != 0)
		answer = false;
		

	return answer;
}