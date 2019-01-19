#include <vector>
#include <iostream>

using namespace std;

vector<int> solution5(vector<int> arr)
{
	vector<int> answer;
	int prev = arr[0];
	answer.push_back(arr[0]);

	for (int i = 1; i < arr.size(); i++) {
		if (prev != arr[i])
			answer.push_back(arr[i]);
		prev = arr[i];
	}
	
	return answer;
}