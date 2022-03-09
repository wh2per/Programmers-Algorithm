#include <iostream>
#include <string>
using namespace std;

int solution(int n)
{
	int answer = 0;
	string s = to_string(n);
	for (int i = 0; i < s.length(); i++) {
		answer += s[i] - '0';
	}

	return answer;
}