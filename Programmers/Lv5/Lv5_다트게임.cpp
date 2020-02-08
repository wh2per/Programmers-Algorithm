#include <string>
#include <iostream>
#include <vector>
using namespace std;

int solution(string dartResult) {
	int answer = 0;

	int prev = 0;
	int num = 0;
	int index = 0;
	vector<int> ans;
	for (int i = 0; i < dartResult.size(); ++i) {
		if (dartResult[i] == '*') {
			ans[index - 2] = ans[index - 2] * 2;
			ans[index - 1] = ans[index - 1] * 2;
			prev = ans[index - 1];
		}
		else if (dartResult[i] == '#') {
			ans[index - 1] = -ans[index - 1];
			prev = ans[index - 1];
		}
		else {
			num = dartResult[i] - '0';
			++i;
			if (dartResult[i] == '0') {
				num = 10;
				++i;
			}
			char score;
			score = dartResult[i];
			if (score == 'S') {
				num = pow(num, 1);
				ans.push_back(num);
				prev = num;
				++index;
			}
			else if (score == 'D') {
				num = pow(num, 2);
				ans.push_back(num);
				prev = num;
				++index;
			}
			else if (score == 'T') {
				num = pow(num, 3);
				ans.push_back(num);
				prev = num;
				++index;
			}
		}
	}
	
	for (auto a : ans)
		answer += a;
	return answer;
}
