#include <string>
#include <vector>

using namespace std;

vector<int> solution2(vector<int> prices) {
	vector<int> answer;
	int count;

	for (int i = 0; i < prices.size() - 1; i++) {
		count = 0;
		for (int j = i + 1; j < prices.size(); j++) {
			count++;
			if (prices[i] > prices[j])
				break;
		}
		answer.push_back(count);
	}
	answer.push_back(0);
	return answer;
}