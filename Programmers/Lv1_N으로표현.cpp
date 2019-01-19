#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int mincount = -1;
void go(int N, int number, int result, int count) {
	if (count > 8) {			// 종료조건
		return;
	}
	if (number == result) {		// 완료조건
		if (count < mincount || mincount == -1) {		// 원래 answer값보다 작으면 넣어줌
			mincount = count;
		}
		return;
	}

	int nn = 0;
	for (int i = 0; i < 8; i++) {
		nn = nn * 10 + N;		// N, NN, NNN, NNNN .....
		go(N, number, result + nn, count + 1 + i);		// i는 N이 몇개 붙어있는 지
		go(N, number, result * nn, count + 1 + i);
		go(N, number, result - nn, count + 1 + i);
		go(N, number, result / nn, count + 1 + i);

	}
}
int solution3(int N, int number) {
	go(N, number, 0, 0);
	return mincount;
}
