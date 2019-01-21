#include <string>
#include <vector>

using namespace std;

string solution51(int num) {
	string answer = "";
	if (num % 2 == 0)
		answer = "Even";
	else
		answer = "Odd";
	return answer;
}