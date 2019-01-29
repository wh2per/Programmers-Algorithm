#include <string>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution32(vector<int> priorities, int location) {
	int answer = 0;
	bool check[100] = { false, };         // 검사한 작업인지 체크
	vector<int> temp = priorities;      // 우선순위 순으로 정렬
	int p = priorities[location];       // 정답
	int count = priorities.size();
	int i = 0, j = 0;
	int cp = 0;     // 현재 우선순위

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

/*

새로 추가한 풀이

int solution32(vector<int> priorities, int location) {
	int answer = 0;
	bool check = true;
	priority_queue <int, vector<int>, less<int>> pq;
	list<pair<int,int>> l;

	for (int i = 0; i < priorities.size(); i++) {
		pq.push(priorities[i]);
		l.push_back(make_pair(priorities[i],i));
	}

	do {
		int now = l.front().second;
		int prior = l.front().first;

		int p = pq.top();
		if (prior == p) {		// 가능
			l.pop_front();
			pq.pop();
			answer++;
			if (now == location)
				check = false;
		}
		else {					// 불가능
			l.pop_front();
			l.push_back(make_pair(prior, now));
		}
	} while (check);

	return answer;
}

*/

