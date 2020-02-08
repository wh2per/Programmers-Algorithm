#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	int currtime = 0;
	int currbus = 1;
	int go = 0;

	int start = 540;
	priority_queue<int, vector<int>, greater<int>> wait;		// 빨리 온 순으로 정렬

	for (int i = 0; i < timetable.size(); i++) {
		int hour = (timetable[i][0] - '0') * 10 + (timetable[i][1]-'0');
		int minute = (timetable[i][3] - '0') * 10 + (timetable[i][4] - '0');
		wait.push(hour * 60 + minute);
	}

	
	while (currbus<=n) {
		if (wait.empty()) {		// 대기자가 없을 때
			currtime = 540 + t * (n - 1);		// 제일 마지막차 타기
			break;
		}
		else {		// 대기자가 있을 때
			if (start < wait.top()) {		// 탈 수 없는 대기자라면
				if (currbus == n) {			// 이 버스 막차면 타야함
					currtime = 540 + t * (n - 1);
					break;
				}
				// 새로운 버스 오라고 하자
				start += t; 
				++currbus;
				go = 0;
			}
			else {							// // 탈 수 있는 대기자라면
				if (go == m - 1 && currbus == n) {		// 내가 꼭 타야하는 상황..
					currtime = wait.top() - 1;		// 얘보다 1분 일찍오면 탐
					break;
				}
				wait.pop();
				++go;
			}
		}

		if (go == m) {		// 버스 꽉찼으면 버스 보내자
			start += t;
			++currbus;
			go = 0;
		}
	}

	if (currtime / 60 >= 10) 	
		answer += to_string(currtime / 60);
	else {
		answer += "0";
		answer += to_string(currtime / 60);
	}
	answer += ":";

	if (currtime % 60 >= 10) 
		answer += to_string(currtime % 60);
	else {
		answer += "0";
		answer += to_string(currtime % 60);
	}

	return answer;
}
