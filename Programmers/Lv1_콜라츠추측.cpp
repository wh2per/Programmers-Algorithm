#include <string>
#include <vector>

using namespace std;

int solution53(int num) {
	int answer = 0;
	long n = num;
	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
			answer++;
		}
		else {
			n *= 3;
			n += 1;
			answer++;
		}
		if (answer > 500) {
			answer = -1;
			break;
		}
	}
	return answer;
}
