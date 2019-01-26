#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution90(int n, vector<int> times) {
	sort(times.begin(), times.end());
	unsigned long long mid = 0;
	unsigned long long high = n * times[times.size() - 1];
	unsigned long long low = 1;
	int count = 0;

	while (low+1 < high) {
		mid = (high + low) / 2;
		count = 0;
		for (int i = 0; i < times.size(); i++)
			count += mid / times[i];

		if (count >= n)
			high = mid;
		else
			low = mid;
	}
	
	return high;
}
