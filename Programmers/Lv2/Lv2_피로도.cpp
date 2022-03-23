#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer;

void dfs(int hp, int cnt, vector<bool> check, vector<vector<int>> dungeons) {
    if (answer < cnt)
        answer = cnt;

    for (int i = 0; i < dungeons.size(); ++i) {
        if (!check[i] && hp >= dungeons[i][0]) {
            check[i] = true;
            dfs(hp - dungeons[i][1], cnt + 1, check, dungeons);
            check[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> check(dungeons.size(), false);
    
    dfs(k, 0, check, dungeons);

    return answer;
}

int main() {
    int k = 80;
    vector<vector<int>> dungeons = {{80, 20}, {50, 40}, {30, 10}};
    cout << solution(k, dungeons);
    return 0;
}