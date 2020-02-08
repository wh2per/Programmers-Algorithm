#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
	int l = 0;
	int r = 0;

	if (s[0] == ')')
		return false;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') 
			l++;
		else
			r++;
		if (r > l)
			return false;
	}
	if (l != r)
		return false;
	else
		return true;
}