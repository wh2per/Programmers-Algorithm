﻿#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
	string a = "수박";
	string b = "수";
	
	for (int i = 0; i < n / 2; i++)
		answer+=a;
	if (n % 2 == 1)
		answer += b;

	return answer;
}