#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int index = 0;

	for (int i = 1; i <= n; i++) {
		if (index<stations.size() && i >= stations[index] - w) {
			i = stations[index] + w;
			index++;
		}
		else {
			i += (2 * w);
			if (i > n)
				i = n;
			answer++;
		}
	}

	return answer;
}
