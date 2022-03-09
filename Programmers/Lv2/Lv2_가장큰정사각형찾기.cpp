#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DP 사용
int solution(vector<vector<int>> board)
{
	int xlen = board[0].size();
	int ylen = board.size();
	int answer = 0;

	if (xlen < 2 || ylen < 2) {					// 가로,세로 중 하나라도 1이면 커봐야 1
		for (int i = 0; i < ylen; i++) {
			for (int j = 0; j < xlen; j++) {
				if (board[i][j] == 1)
					answer = 1;
			}
		}
	}
	else {	
		for (int i = 1; i < ylen; i++) {
			for (int j = 1; j < xlen; j++) {
				if (board[i][j] == 1) {
					board[i][j] = min({ board[i][j - 1], board[i - 1][j], board[i - 1][j - 1] }) + 1;
					if (answer < board[i][j])
						answer = board[i][j]; 
				}
			}
		}
	}

	answer *= answer;
	return answer;
}
