#include <string>
#include <vector>
#include <math.h>
using namespace std;

long long solution49(long long n) {
	long long answer = 0;
	long long temp = sqrt(n);
	if (temp*temp == n)
		answer = (temp + 1)*(temp + 1);
	else
		answer = -1;
	return answer;
}