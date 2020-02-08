#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool is_prime(int n) {
	int i;
	for (i = 2; i < n; i++) {
		if (n%i == 0)
			return false;
	}
	return true;		//¼Ò¼ö
}

int solution(string numbers) {
	int answer = 0;
	int size = numbers.length();
	vector<int> v;
	vector<bool> c(1000000);

	for (int i = 0; i < size; i++)
		v.push_back(numbers[i] - '0');

	sort(v.begin(), v.end());

	do {
		for (int k = 1; k <= v.size(); k++) {
			string s = "";
			int n = 0;
			bool check = false;
			for (int i = 0; i < k; i++) {
				if (check == false && v[i] != 0)
					check = true;
				if (check)
					s += to_string(v[i]);
			}
			n = atoi(s.c_str());
			if (is_prime(n) && n > 1 && c[n] == false) {
				answer++;
				c[n] = true;
			}
		}
	} while (next_permutation(v.begin(), v.end()));

	return answer;
}