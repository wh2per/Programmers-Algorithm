#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string s) {
	int slen = s.length();
	int answer = slen;

	for (int i = 1; i <= slen; ++i) {
		int ans = i;			
		string start = s.substr(0, i);
		int index = i;			// ½ÃÀÛ ÀÎµ¦½º
		int count = 1;

		while (index < slen) {
			int npos = i;
			if (index + npos >= slen)
				npos = slen - index;

			string ns = s.substr(index, npos);

			if (start == ns) {
				++count;
			}
			else {
				if (count != 1) {
					int num = to_string(count).length();
					ans += num;
				}
				ans += npos;
				count = 1;
			}
			
			start = ns;
			index += npos;
		}
		if (count != 1) {
			int num = to_string(count).length();
			ans += num;
		}
		answer = min(answer, ans);
	}

	return answer;
}

int main() {

	cout << solution("aabbaccc");

	return 0;
}