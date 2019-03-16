#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <sstream>
#include <map>
using namespace std;

void line1() {
	int ans1=0;
	int ans2 = 0;
	long long i;
	long long N;
	cin >> N;
	for (i = 1; i*i < N; i++) {
		if (N%i == 0)
			ans1 = i;
	}
	if (i*i == N)
		ans1 = i;
	ans2 = N / ans1;
	cout << abs(ans2 - ans1);
}

void line2() {
	string N;
	int i;
	string ans = "";

	cin >> N;
	queue<string> q;

	for (i = 0; !isdigit(N[i]); i++){
		if (isupper(N[i])) {
			if (islower(N[i + 1]))
				q.push(N.substr(i, 2));
			else
				q.push(N.substr(i, 1));
		}
	}

	for (; i < N.size(); i++) {
		if (q.empty()) {
			ans = "error";
			break;
		}
		ans += q.front();
		q.pop();
		if (N[i] == '1') {
			if (i < N.size() - 1 && N[i + 1] == '0') {
				ans += "10";
				++i;
			}
			else
				ans += "";
		}
		else
			ans += N[i];
	}

	if (!q.empty())
		ans = "error";
	cout << ans;
}


void line3() {
	map<int,vector<string>> t1;
	map<int, vector<string>> t2;
	map<int, vector<string>> t3;
	vector<string> header;
	
	int col1, row1=0;
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

	int col2,row2=0;
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
		t2.insert(make_pair(id,temp));
	}
	
	int row3 = row1 + row2 - 1;		// t2의 id하나 제거
	for (auto i: t1) {
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

void line4() {
	int N;
	cin >> N;
	vector<int> top(N, 0);

	for (int i = 0; i < N; i++)
		cin >> top[i];
	
	int answer = INT_MIN;
	int size = top.size();

	for (int i = 0; i < size-1; i++) {
		for (int j = i+1; j < size; j++) {		// 오른쪽 검사
			if (top[i] <= top[j]) {
				if (answer < j-i)
					answer = j-i;
				break;
			}
		}
	}
	for (int i = size-1; i > 0 ; i--) {
		for (int j = i-1; j >= 0; j--) {			// 왼쪽 검사
			if (top[i] <= top[j]) {
				if (answer < j-i)
					answer = i=j;
				break;
			}
		}
	}
	
	cout << answer;
}

void line5() {
	queue<int> q;
	int min = 0;
	int max = 200001;

	int cony, brown;
	cin >> cony;
	cin >> brown;

	int n = 1;
	while (cony + (n * (n + 1) / 2) <= max)
		n++;

	vector<int> cony_pos(n);
	vector<bool> check(max);
	vector<int> brown_pos(max);

	cony_pos[0] = cony;
	for (int i = 1; i < n; i++) 
		cony_pos[i] = cony_pos[i - 1] + i;
	
	check[brown] = true;
	brown_pos[brown] = 0;
	q.push(brown);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now - 1 >= min) {
			if (check[now - 1] == false) {
				q.push(now - 1);
				check[now - 1] = true;
				brown_pos[now - 1] = brown_pos[now] + 1;
			}
		}

		if (now + 1 <= max) {
			if (check[now + 1] == false) {
				q.push(now + 1);
				check[now + 1] = true;
				brown_pos[now + 1] = brown_pos[now] + 1;
			}
		}

		if (now * 2 <= max) {
			if (check[now * 2] == false) {
				q.push(now * 2);
				check[now * 2] = true;
				brown_pos[now * 2] = brown_pos[now] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (brown_pos[cony_pos[i]] == i) {
			cout << brown_pos[cony_pos[i]];
			return;
		}
	}
	cout << -1;
}
