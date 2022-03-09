#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int size = number.length() - k;
	int size2 = size;
	int len = k;
	int end = size;

	while (answer.length()!=size2) {
		int high = -1;
		int index = -1;
		char temp = '0';

		int end = number.length() - size + 1;
		if (number.length() >= end) {
			for (int i = 0; i < end; i++) {
				if (high < number[i] - 48) {
					high = number[i] - 48;
					index = i;
				}
			}
			answer.push_back(temp + high);
			number = number.substr(index + 1);
			size--;
		}

		if (number.length() == size) {
			for (int i = 0; i < number.length(); i++)
				answer.push_back(number[i]);
		}
	}
	return answer;
}

