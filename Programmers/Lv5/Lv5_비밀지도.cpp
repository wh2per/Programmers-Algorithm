#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer(n);
	for (int i = 0; i < n; i++) {
		int value = arr1[i] | arr2[i];
		string temp = "";
		for (int i = 0; i < n; ++i)
			temp += " ";
		answer[i] = temp;
		for (int j = n - 1; j >= 0; j--) {
			if (value % 2 == 0)
				answer[i][j] = ' ';
			else
				answer[i][j] = '#';
			value /= 2;
		}
	}
	return answer;
}