#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

vector<pair<int, int> > pos['Z'+1];
char temp_game[101][101];

const int dy[] = {0,1,0,-1};
const int dx[] = {1,0,-1,0};

bool block_remove(char dest, int m, int n) {
	int sy = pos[dest][0].first;
	int sx = pos[dest][0].second;
	temp_game[sy][sx] = '.';

	for (int d = 0; d < 4; ++d) {		// 4방향으로 진행
		int ny = sy + dy[d];
		int nx = sx + dx[d];

		// 현재방향으로 한칸씩 전진하면서 양옆으로 쭉 가보고 성공하면 return true;
		while (ny >= 0 && ny < m && nx >= 0 && nx < n && (temp_game[ny][nx] == '.' || temp_game[ny][nx] == dest)) {		// 전진
			if (temp_game[ny][nx] == dest) {
				temp_game[ny][nx] = '.';
				return true;
			}

			// 왼쪽 검사
			int ldir = (d + 7) % 4;
			int ly = ny + dy[ldir];
			int lx = nx + dx[ldir];
			while (ly >= 0 && ly < m && lx >= 0 && lx < n && (temp_game[ly][lx] == '.' || temp_game[ly][lx] == dest)) {
				if (temp_game[ly][lx] == dest) {
					temp_game[ly][lx] = '.';
					return true;
				}
				ly = ly + dy[ldir];
				lx = lx + dx[ldir];
			}

			// 오른쪽 검사
			int rdir = (d + 5) % 4;
			int ry = ny + dy[rdir];
			int rx = nx + dx[rdir];
			while (ry >= 0 && ry < m && rx >= 0 && rx < n && (temp_game[ry][rx] == '.' || temp_game[ry][rx] == dest)) {
				if (temp_game[ry][rx] == dest) {
					temp_game[ry][rx] = '.';
					return true;
				}
				ry = ry + dy[rdir];
				rx = rx + dx[rdir];
			}

			ny = ny + dy[d];		// 한칸 전진
			nx = nx + dx[d];
		}
	}
	return false;
}

string solution140(int m, int n, vector<string> board) {
	string answer = "";
	for (int i = 0; i < 'Z'; i++) 
		pos[i].clear();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			temp_game[i][j] = board[i][j];
			if (board[i][j] >=65)
				pos[board[i][j]].push_back(make_pair(i, j));
		}
	}

	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 'A'; i <= 'Z'; ++i) {
			if (pos[i].empty())
				continue;
			flag = block_remove(i,m,n);
			if (flag) {
				pos[i].clear();
				answer += i;
				break;
			}
			else {
				temp_game[pos[i][0].first][pos[i][0].second] = i;
				temp_game[pos[i][1].first][pos[i][1].second] = i;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (temp_game[i][j] != '.' && temp_game[i][j] != '*') 
				return "IMPOSSIBLE";
		}
	}

	return answer;
}
