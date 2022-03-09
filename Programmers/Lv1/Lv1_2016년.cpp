#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int a, int b) {
	vector<string> v = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	int index = 0;
	if (a == 1 || a==4 || a==7) index = 5;
	else if (a == 2 || a==8) index = 1;
	else if (a == 3 || a==11) index = 2;
	else if (a == 5) index = 0;
	else if (a == 6) index = 3;
	else if (a == 9 || a==12) index = 4;
	else if (a == 10) index = 6;

	index += b % 7;
	if (index > 6) index -= 7;

	if (index == 0)
		index = 6;
	else
		index--;
	return v[index];
}

