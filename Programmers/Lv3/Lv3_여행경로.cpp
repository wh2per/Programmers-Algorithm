#include <string>
#include <vector>

using namespace std;

vector<bool> check;
string tmp = "a";

void DFS(vector<vector<string>> &tickets, string end, int count, string path) {			// ticket을 넘길 때 주소값으로 보내야 시간이 줄어듬!
	if (count >= tickets.size()) {
		string p = path;
		if (tmp > p)
			tmp = p;
		return;
	}

	for (int i = 0; i < tickets.size(); i++) {			// 사용할 티켓 찾기
		if (tickets[i][0] == end && check[i] == false) {
			check[i] = true;
			DFS(tickets, tickets[i][1], count + 1, path + tickets[i][1]);
			check[i] = false;
		}
	}
}

vector<string> solution88(vector<vector<string>> tickets) {
	vector<string> answer;
	check.resize(tickets.size());
	DFS(tickets, "ICN", 0, "ICN");

	for (int i = 0; i < tmp.size(); i += 3)
		answer.push_back(tmp.substr(i, 3));

	return answer;
}
