#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

bool arr[101][101];

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    int count = 0;

    for (auto a : wires) {
        arr[a[0]][a[1]] = true;
        arr[a[1]][a[0]] = true;
    }

    for (auto a : wires) {
        arr[a[0]][a[1]] = false;
        arr[a[1]][a[0]] = false;

        count = 1;
        
        queue<int> q;
        vector<bool> check(101, false);

        q.push(1);
        check[1] = true;
        while (!q.empty()) {
            int now = q.front();
            q.pop();

            for (int i = 1; i <= n; ++i) {
                if (!check[i] && arr[now][i]) {
                    ++count;
                    q.push(i);
                    check[i] = true;
                }
            }
        }

        if (abs(n-count-count) < answer) 
            answer = abs(n - count - count);

        if (answer == 0)
            break;

        arr[a[0]][a[1]] = true;
        arr[a[1]][a[0]] = true;
    }

    return answer;
}

int main() {
    vector<vector<int>> wires1 = { {1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9} };
    vector<vector<int>> wires2 = {{1, 2}, {2, 3}, {3, 4}};
    vector<vector<int>> wires3 = {{1, 2}, {2, 7}, {3, 7}, {3, 4}, {4, 5}, {6, 7}};
    cout << solution(4, wires2);
    return 0;
}