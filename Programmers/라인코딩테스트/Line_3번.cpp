#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <map>
using namespace std;

void line3() {
	map<int, vector<string>> t1;
	map<int, vector<string>> t2;
	map<int, vector<string>> t3;
	vector<string> header;

	int col1, row1 = 0;
	string h1, str1;
	cin >> col1;
	getline(cin, h1);		// 이전 개행문자 날리기
	getline(cin, h1);
	stringstream ss1(h1);
	while (ss1 >> str1) {
		header.push_back(str1);
		++row1;
	}

	for (int i = 1; i < col1; i++) {
		int id;
		cin >> id;
		vector<string> temp;
		for (int j = 0; j < row1 - 1; j++) {
			string t;
			cin >> t;
			temp.push_back(t);
		}
		t1.insert(make_pair(id, temp));
	}

	int col2, row2 = 0;
	string h2, str2;
	cin >> col2;
	getline(cin, h2);
	getline(cin, h2);
	stringstream ss2(h2);
	while (ss2 >> str2) {
		if (str2 != "id") {
			header.push_back(str2);
		}
		++row2;
	}
	for (int i = 1; i < col2; i++) {
		int id;
		cin >> id;
		vector<string> temp;
		for (int j = 0; j < row2 - 1; j++) {
			string t;
			cin >> t;
			temp.push_back(t);
		}
		t2.insert(make_pair(id, temp));
	}

	int row3 = row1 + row2 - 1;		// t2의 id하나 제거
	for (auto i : t1) {
		int id = i.first;
		vector<string> temp;
		for (int j = 0; j < row1 - 1; j++)
			temp.push_back(i.second[j]);
		if (t2.find(id) != t2.end()) {
			vector<string> k = t2[id];
			for (int m = 0; m < row2 - 1; m++)
				temp.push_back(k[m]);
		}
		else {
			for (int m = 0; m < row2 - 1; m++)
				temp.push_back("NULL");
		}
		t3.insert(make_pair(id, temp));
	}
	for (auto s : header)
		cout << s << " ";
	cout << '\n';
	for (auto ans : t3) {
		cout << ans.first << " ";
		for (auto ans_left : ans.second)
			cout << ans_left << " ";
		cout << '\n';
	}
}