#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution6(vector<int> priorities, int location) {
	int answer = 0;
	bool check[100] = { false, };			// 검사한 작업인지 체크
	vector<int> temp = priorities;		// 우선순위 순으로 정렬
	int p = priorities[location];		// 정답
	int count = priorities.size();
	int i = 0, j = 0;
	int cp = 0;		// 현재 우선순위

	sort(temp.begin(), temp.end(), greater<int>());
	cp = temp[i];

	while (count != 0) {
		if ((check[j] == false) && (cp == priorities[j])) {
			check[j] = true;
			count--;
			i++;
			answer++;
			if ((cp == p) && (j == location))
				break;
			cp = temp[i];
		}
		j++;
		if (j == priorities.size())
			j = 0;

	}

	return answer;
}
