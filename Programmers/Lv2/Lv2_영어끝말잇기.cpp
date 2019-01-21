#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution73(int n, vector<string> words) {
	vector<int> answer;
	char prev = words[0][words[0].length() - 1];
	vector<string>::iterator iter;
	int i = 1;
	for (iter = words.begin()+1; iter != words.end(); ++iter) {
		string temp = *iter;
		if (prev != temp[0]) {
			answer.push_back((i + 1) % n);
			answer.push_back((i/n)+1);
			break;
		}
		else {
			vector<string>::iterator it;
			it = find(words.begin(), iter-1, temp);
			if (it != iter-1) {
				answer.push_back((i) % n);
				answer.push_back((i / n) + 1);
				break;
			}
		}
		prev = words[i][words[i].length() - 1];
		i++;
	}
	if (answer.size() == 0) {
		answer.push_back(0);
		answer.push_back(0);
	}
	return answer;
}
