#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;
	if (s / n == 0)
		return { -1 };
	else {
		int q = s / n;
		int r = s % n;
		int j = n - 1;
		for(int i=0; i<n; i++)
			answer.push_back(q);
		while (r != 0) {
			answer[j--]++;
			r--;
		}
	}
	return answer;
}

