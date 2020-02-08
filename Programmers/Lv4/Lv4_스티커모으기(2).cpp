#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
	int answer = 0;
	vector<int> d(sticker.size(), 0);

	if (sticker.size() == 1)
		return sticker[0];
	else if (sticker.size() == 2)
		return max(sticker[0], sticker[1]);
	else {
		// 첫번째 스티커 사용
		d[0] = sticker[0];
		d[1] = sticker[0];

		for (int i = 2; i < sticker.size() - 1; i++) 		// 맨마지막은 사용 불가
			d[i] = max(d[i - 2] + sticker[i], d[i - 1]);
		answer = d[sticker.size() - 2];

		// 첫번째 스티커 사용 x
		d[0] = 0;
		d[1] = sticker[1];
		for (int i = 2; i < sticker.size(); i++)
			d[i] = max(d[i - 2] + sticker[i], d[i - 1]);

		answer = max(answer, d[sticker.size() - 1]);
	}
	
	return answer;
}
