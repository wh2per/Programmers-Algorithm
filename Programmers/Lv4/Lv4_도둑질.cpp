#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution123(vector<int> money) {
	int answer = 0;
	vector<int> d(money.size(), 0);

	// 첫번째 집 털기 -> 마지막 집은 못 턴다는 뜻
	d[0] = money[0];
	d[1] = money[0];

	for (int i = 2; i < money.size() - 1; i++)		// 마지막 원소 전까지(마지막 집은 못 털기 때문에)
		d[i] = max(d[i - 2] + money[i], d[i - 1]);	
	answer = d[money.size() - 2];

	// 첫번째 집 털기 x -> 두번째 집부터 털기
	d[0] = 0;
	d[1] = money[1];
	for (int i = 2; i < money.size(); i++)		// 마지막 원소까지(마지막 집도 털 수 있기 때문에)
		d[i] = max(d[i - 2] + money[i], d[i - 1]);

	answer = max(answer, d[money.size() - 1]);
	return answer;
}
