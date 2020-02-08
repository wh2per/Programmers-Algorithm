#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			int check = 0;
			if (s[i] < 91 && s[i]>64)		// 대문자
				check = 1;
			else if (s[i] < 123 && s[i]>96)		// 소문자
				check = 2;
			
			if ((check == 1 && s[i] + n > 90) || (check == 2 && s[i] + n > 122)) {
				n = n % 26;
				s[i] = s[i] + n;
				s[i] -= 26;
			}else
				s[i] = s[i] + n;
		}
	}
	return s;
}