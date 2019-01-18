#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution1(vector<int> people, int limit) {
	int answer = 0;
	int index = 0;
	sort(people.begin(), people.end());

	while (people.size()-index !=0) {
		int end = people.size() - 1;
		if (end == index) {		//한 명 남았을 때
			answer++;
			break;
		}
		else {
			int sum = people[index] + people[end];
			bool check = true;
			while (sum > limit) {
				people.pop_back();
				answer++;
				end = people.size() - 1;
				if (end == index) {
					check = false;
					break;
				}
				sum = people[index] + people[end];
			}
			answer++;
			if (check)
				people.pop_back();
			index++;
		}
	}
	return answer;
}

/*
int solution(vector<int> people, int limit) {
	int answer = 0;
	int size = people.size();

	sort(people.begin(), people.end());
	reverse(people.begin(), people.end());

	for (int i = 0, j = size - 1; i <= j; i++) {
		if (people[i] + people[j] <= limit) {
			j--;
		}
		answer++;
	}
	return answer;
}
*/
