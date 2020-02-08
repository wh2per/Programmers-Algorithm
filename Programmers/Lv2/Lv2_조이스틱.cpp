#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string name) {
	int answer = 0;
	int answer1 = 0;
	int c1 = 0;
	int answer2 = 0;
	int c2 = 0;
	int size = name.length();

	for (int i = 0; i < size; i++) {
		int temp = name[i] - 'A';
		if (name[i] == 'A')
			c1++;
		else c1 = 0;
		if (temp > 13)
			temp = 26 - temp;
		answer1 += temp;
		answer1++;
	}
	answer1--;
	answer1 -= c1;

	answer2 += name[0] - 'A';
	answer2++;
	for (int i = size - 1; i > 0; i--) {
		int temp = name[i] - 'A';
		if (name[i] == 'A')
			c2++;
		else
			c2 = 0;
		if (temp > 13)
			temp = 26 - temp;
		answer2 += temp;
		answer2++;
	}
	answer2--;
	answer2 -= c2;

	answer = min(answer1, answer2);
	return answer;
}