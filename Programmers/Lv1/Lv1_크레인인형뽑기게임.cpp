#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

stack<int> arr[30];

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    for (int i = board.size() - 1; i >= 0; --i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if(board[i][j] != 0)
                arr[j].push(board[i][j]);
        }
    }

    stack<int> ans;

    for (auto a : moves) {
        int top = 0;
        if (ans.size() > 0)
            top = ans.top();

        if (arr[a-1].size() > 0) {
            int doll = arr[a-1].top();
            arr[a-1].pop();

            if (top == doll) {
                answer += 2;
                ans.pop();
            }
            else
                ans.push(doll);
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> board = { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3 }, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1} };
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};
    cout << solution(board, moves);
    return 0;
}