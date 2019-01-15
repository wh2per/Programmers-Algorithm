#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int i = 0; i < commands.size(); i++) {
		int begin = commands[i][0];
		int end = commands[i][1];
		int index = commands[i][2] - 1;
		vector<int> temp;
		for (int j = begin - 1; j <= end - 1; j++) {
			temp.push_back(array[j]);
		}
		sort(temp.begin(), temp.end());
		answer.push_back(temp[index]);
	}
	return answer;
}