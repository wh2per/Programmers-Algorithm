#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	for (int i = red; i >0; i--) {
		if (red%i == 0) {
			int width = i;
			int height = red/i;
			if ((width + 2) * 2 + height * 2 == brown) {
				answer.push_back(width + 2);
				answer.push_back(height + 2);
				break;
			}
		}
	}
	return answer;
}
