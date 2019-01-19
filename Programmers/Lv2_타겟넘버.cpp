#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = 0;

int oper(int i, int num, int sum) {
	if (i == 0) {				// 더하기
		sum += num;
	}
	else if (i == 1) {			// 빼기
		sum -= num;
	}
	return sum;
}

void go(vector<int> numbers, int target, int index,int result) {
	if (result == target && index == numbers.size()) {			// 완료조건
		answer++;
		return;
	}
	if (index > numbers.size() - 1)								// 종료조건
		return;
	for (int i = 0; i < 2; i++) 
		go(numbers, target, index + 1, oper(i, numbers[index], result));
}

int solution30(vector<int> numbers, int target) {
	go(numbers,target,0,0);
	
	return answer;
}
