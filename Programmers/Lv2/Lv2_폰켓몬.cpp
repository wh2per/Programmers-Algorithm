#include <vector>
#include <algorithm>
using namespace std;

int solution63(vector<int> nums)
{
	int answer = 0;
	int get = nums.size() / 2;
	int kind = 1;
	sort(nums.begin(), nums.end());
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] != nums[i - 1])
			kind++;
	}
	if (get <= kind)
		answer = get;
	else
		answer = kind;
	return answer;
}