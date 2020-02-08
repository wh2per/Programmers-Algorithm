#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 0;
	while (n != 0){
		answer++;		// ¶ó¿îµå 
		n /= 2;
		if (a/2 != b/2 && abs(a - b) == 1)
			break;
		if (a % 2 == 1)
			a++; 
		if (b % 2 == 1)
			b++;
		a /= 2;
		b /= 2;
	}
	return answer;
}
