#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	char temp;
	if (s[0] == '-') {
		temp = s[0];
		s = s.substr(1, s.length());
		answer -= atoi(s.c_str());
	}
	else {
		answer += atoi(s.c_str());
	}

	return answer;
}