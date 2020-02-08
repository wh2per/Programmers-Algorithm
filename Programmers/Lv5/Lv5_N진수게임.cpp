#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

string solution(int n, int t, int m, int p) {
	vector<string> left = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
	string answer;
	int count = 0, turn = 2, num = 1;
	if (p == 1) {
		answer += "0";
		++count;
	}
	if (m == p)
		p = 0;
	
	bool flag = false;

	while (count < t) {
		int temp = num;
		stack<string> s;
		while (temp > 0) {
			s.push(left[temp%n]);
			temp /= n;
		}

		while (!s.empty()) {
			string value = s.top();
			s.pop();
			if (turn%m == p) {		// 내 턴일 때
				answer += value;
				++count;
			}
			if (count >= t) {
				flag = true;
				break;
			}
			++turn;
		}
		if (flag)
			break;
		++num;
	}
	return answer;
}
