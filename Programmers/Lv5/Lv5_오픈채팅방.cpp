#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> info;
	for (int i = 0; i < record.size(); ++i) {
		stringstream ss;
		ss.str(record[i]);
		string command, uid, nick;
		ss >> command;
		ss >> uid;
		ss >> nick;

		if (command == "Enter" || command=="Change")				// 입장, 닉네임 변경
			info[uid] = nick;
	}

	for (int i = 0; i < record.size(); ++i) {
		stringstream ss;
		ss.str(record[i]);
		string command, uid, nick;
		ss >> command;
		ss >> uid;
		ss >> nick;
		if (command == "Enter") 
			answer.push_back(info[uid]+"님이 들어왔습니다.");
		else if (command == "Leave") 
			answer.push_back(info[uid] + "님이 나갔습니다.");
	}

	return answer;
}