#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct info_file {
	string head;
	int num;
	int recent;
};

bool cmp_file(info_file a, info_file b) {
	if (a.head < b.head) 
		return true;
	else if (a.head == b.head) {
		if (a.num < b.num)
			return true;
		else if (a.num == b.num) {
			if (a.recent < b.recent)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}


vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<info_file> order;

	for (int i = 0; i < files.size(); ++i) {
		string file = files[i];
		int t1 = 0;
		while (file[t1] < 48 || file[t1] > 57) 		// 숫자가 아닐때
			++t1;
		string head = file.substr(0, t1);
		int t2 = t1;
		while (file[t2] >= 48 && file[t2] <= 57) 		// 숫자 일때
			++t2;

		for (int j = 0; j < head.length(); ++j)
			head[j] = tolower(head[j]);
		int num = atoi((file.substr(t1, t2 - t1)).c_str());
		order.push_back({head,num,i});
	}

	sort(order.begin(), order.end(), cmp_file);
	for (int i = 0; i < order.size(); ++i) 
		answer.push_back(files[order[i].recent]);

	return answer;
}