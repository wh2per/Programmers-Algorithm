﻿#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isprime(int n) {
	int i;
	for (i = 2; i < n; i++) {
		if (n%i == 0)
			return false;
	}
	return true;		//소수
}

int solution(vector<int> nums) {
	int answer = 0;
	vector<int> v(nums.size());
	v[0] = 1; v[1] = 1; v[2] = 1;
	sort(v.begin(), v.end());

	do {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (v[i] == 1)
				sum += nums[i];
		}
		if (isprime(sum))
			answer++;
	} while (next_permutation(v.begin(), v.end()));
	
	return answer;
}
