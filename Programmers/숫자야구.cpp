#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution5(vector<vector<int>> baseball) {
	int answer = 0;
	vector<int> v = { 0,0,0,0,0,0,1,1,1 };
	do {										// 숫자 3개 고르기
		vector<int> b;
		for (int i = 0; i < 9; i++) {
			if (v[i] == 1)
				b.push_back(i + 1);
		}
		do {									// 숫자 3개를 재배열 하기
			int j = 0;
			for (j = 0; j < baseball.size(); j++) {
				int strike = 0;
				int ball = 0;
				string shoot = to_string(baseball[j][0]);
				for (int k = 0; k < 3; k++) {
					for (int h = 0; h < 3; h++) {
						if (b[k] == shoot[h] - '0') {
							if (k != h)
								ball++;
							else
								strike++;
						}
					}
				}
				if (strike != baseball[j][1] || ball != baseball[j][2])
					break;
			}
			if (j == baseball.size())
				answer++;
		} while (next_permutation(b.begin(), b.end()));
	} while (next_permutation(v.begin(), v.end()));

	return answer;
}
