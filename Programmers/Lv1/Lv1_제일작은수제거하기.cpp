#include <string>
#include <vector>
#include <list>
using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;
	list<int> l(arr.begin(), arr.end());
	int min = 99999999;

	for (int i = 0; i < arr.size(); i++) {
		if (min > arr[i])
			min = arr[i];
	}

	l.remove(min);
	for (auto i : l)
		answer.push_back(i);
	if (l.size() == 0)
		answer.push_back(-1);
	return answer;
}