#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// manacher 알고리즘 
int solution(string s)
{
	int answer = 0;
	string str = "";
	for (int i = 0; i < s.length(); i++) {		// 짝수 펠린드롬을 위해
		str += "#";
		str += s[i];
	}
	str += "#";

	vector<int> A(str.length(),0);
	int r = 0;
	int p = 0;

	for (int i = 0; i < str.length(); i++) {
		// 초기값 설정
		if (i <= r)
			A[i] = min(A[2 * p - i], r - i);
		else
			A[i] = 0;

		while (i - A[i] - 1 >= 0 && i + A[i] + 1 >= 0 && str[i - A[i] - 1] == str[i + A[i] + 1])		// A[i]값을 증가
			A[i]++;

		if (r < i + A[i]) {				// r = max(i+A[i])
			r = i + A[i];
			p = i;
		}
	}

	for (int i = 0; i < A.size(); i++)
		answer = max(answer,A[i]);

	return answer;
}
