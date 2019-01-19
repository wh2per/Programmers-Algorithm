#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

string solution13(int n) {
	string answer = "";
	int arr[3] = { 1,2,4 };
	int r = -1;
	// i-1 ÀÚ¸®¼ö 
	while (n > 0) {
		n -= 1;
		r = n % 3;
		answer += to_string(arr[n % 3]);
		n = n / 3;
	}

	reverse(answer.begin(), answer.end());

	return answer;
}