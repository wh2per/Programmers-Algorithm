#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
vector<int> answer;
bool check[500][500][4];
char arr[500][500];
int dx[4] = { 0,1,0,-1 };   // 위 오른쪽 아래 왼쪽
int dy[4] = { -1,0,1,0 };

void dfs(int y, int x, int dir, int cnt) {
    if (check[y][x][dir]) {
        answer.push_back(cnt - 1);
        return;
    }

    check[y][x][dir] = true;
    char c = arr[y][x];

    int ny, nx;
    int nd = dir;
    if (c == 'L')  
        nd = (dir + 3) % 4;
    else if (c == 'R') 
        nd = (dir + 1) % 4;

    ny = y + dy[nd];
    nx = x + dx[nd];
    if (ny < 0) 
        ny += n;
    else if (ny >= n) 
        ny -= n;

    if (nx < 0) 
        nx += m;
    else if (nx >= m) 
        nx -= m;

    dfs(ny, nx, nd, cnt + 1);
}

vector<int> solution(vector<string> grid) {

    n = grid.size();
    m = grid[0].size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = grid[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                if (check[i][j][k])     // 갔던 곳은 pass
                    continue;
                dfs(i, j, k, 1);
            }
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    vector<string> grid = { "SL", "LR" };
    vector<int> ans = solution(grid);
    for (auto a : ans)
        cout << a << " ";
    return 0;
}