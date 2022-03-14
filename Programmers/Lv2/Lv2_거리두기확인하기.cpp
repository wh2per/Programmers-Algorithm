#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int y;
    int x;
    int count;
};

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

bool check(int y, int x, int i, vector<vector<string>> &places) {
    queue<node> q;
    q.push({ y,x,0 });
    
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    visited[y][x] = true;

    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int count = q.front().count;
        q.pop();

        if (count == 2)
            continue;

        for (int k = 0; k < 4; ++k) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (ny < 0 || ny >4 || nx < 0 || nx>4 || visited[ny][nx])
                continue;
            if (places[i][ny][nx] == 'X')
                continue;
            if (places[i][ny][nx] == 'P' && count <= 1)
                return false;
            visited[ny][nx] = true;
            q.push({ ny,nx,count + 1 });
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < 5; ++i) {
        bool flag = false;
        for (int j = 0; j < 5; ++j) {
            flag = false;
            for (int k = 0; k < 5; ++k) {
                if (places[i][j][k] == 'P') {
                    if (!check(j, k, i,places)) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
                break;
        }

        if (flag)
            answer.push_back(0);
        else
            answer.push_back(1);
    }

    return answer;
}

int main() {
    vector<vector<string>> places = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
    vector<int> ans = solution(places);

    for (auto a : ans)
        cout << a << " ";

    return 0;
}