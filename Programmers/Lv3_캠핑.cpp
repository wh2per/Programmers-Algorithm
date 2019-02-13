#include <vector>
#include <set>
using namespace std;

struct tent_cmp{				// top에 가장 작은 수가 가도록 내림차순 정렬
	bool operator()(pair<int, int> t, pair<int, int> u) {
		if (t.first == u.first)
			return t.second < u.second;
		else
			return t.first < u.first;
	}
};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution104(int n, vector<vector<int>> data) {
	int answer = 0;
	set<pair<int, int>, tent_cmp> s;

	for (int i = 0; i < data.size(); i++)
		s.insert(make_pair(data[i][0], data[i][1]));

	set<pair<int, int>>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		int start_x = iter->first;		// 기준점의 x
		int start_y = iter->second;		// 기준점의 y

		int end_up = start_y;
		int end_up_x = start_x;
		int end_down = start_y;
		int uc = 0;
		int dc = 0;
		set<pair<int, int>>::iterator temp1;
		for (temp1 = iter; temp1 != s.end(); temp1++) {		// 위쪽 한계선 설정
			if (temp1->first != start_x && end_up < temp1->second) {
				end_up = temp1->second;
				end_up_x = temp1->first;
				break;
			}
		}

		set<pair<int, int>>::iterator temp2;
		for (temp2 = iter; temp2 != s.end(); temp2++) {		// 아래쪽 한계선 설정
			if (temp2->first != start_x && end_down > temp2->second) {
				end_down = temp2->second;
				break;
			}
		}
	

		int prev_end_up = end_up;
		int temp_x = end_up_x;
		set<pair<int, int>>::iterator iter2;
		for (iter2 = iter; iter2 != s.end(); iter2++) {
			int end_x = iter2->first;
			int end_y = iter2->second;

			if (end_x == start_x)
				continue;

			if (end_y > start_y) {
				if (end_up >= end_y) {
					prev_end_up = end_up;
					end_up = end_y;		// 새로운 위쪽 한계선 갱신
					temp_x = end_x;
					answer++;
				}
				else {
					if (end_x == end_up_x)
						answer++;
					else if (end_x == temp_x && end_y <= prev_end_up)
						answer++;
				}
			}
			else if (end_y < start_y) {
				if (end_down <= end_y) {
					end_down = end_y;		// 새로운 아래쪽 한계선 갱신
					answer++;
				}
			}
			else
				continue;
		}
	}
	return answer;
}
