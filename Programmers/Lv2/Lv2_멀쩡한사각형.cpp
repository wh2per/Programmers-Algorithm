#include <iostream>
#include <algorithm>
using namespace std;

long long solution(int w, int h)
{
	int gcd;
	long long sum = (long long)w * (long long)h;

	for (int i = (w < h) ? w : h; i > 0; i--) { //최대 공약수 구하기
		if ((w % i == 0) && (h % i == 0)) {
			gcd = i;
			break;
		}
	}
	return sum - (w + h - gcd);
}

int main() {
	cout << solution(8, 12);
	return 0;
}