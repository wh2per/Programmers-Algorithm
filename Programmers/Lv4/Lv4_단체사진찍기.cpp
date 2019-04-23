#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution137(int n, vector<string> data) {
	int answer = 0;
	string friends = "ACFJMNRT";
	string arr;

	do {
		arr = "";
		for (int i = 0; i < 8; i++)
			arr += friends[i];
		bool flag = true;
		for (int i = 0; i < data.size(); i++) {
			char f1 = data[i][0];
			char f2 = data[i][2];
			char con = data[i][3];
			int diff = data[i][4] - '0';
			int pos1 = arr.find(f1);
			int pos2 = arr.find(f2);

			if (con == '>') {
				if (abs(pos1 - pos2) - 1 <= diff)
					flag = false;
			}
			else if (con == '<') {
				if (abs(pos1 - pos2) - 1 >= diff)
					flag = false;
			}
			else {
				if (abs(pos1 - pos2) - 1 != diff)
					flag = false;
			}
		}
		if (flag)
			++answer;
	} while (next_permutation(friends.begin(), friends.end()));

	return answer;
}
