#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	bool answer = true;
	int p = 0;
	int y = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'P' || s[i] == 'p')
			p++;
		if (s[i] == 'Y' || s[i] == 'y') 
			y++;
	}
	
	if (p != y)
		answer = false;

	return answer;
}