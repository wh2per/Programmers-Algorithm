#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr[101][101];

int rotate(int y1, int x1, int y2, int x2) {
    int ret = 987654321;
    int y1x1 = arr[y1][x1];
    int y1x2 = arr[y1][x2];
    int y2x1 = arr[y2][x1];
    int y2x2 = arr[y2][x2];

    int origin = arr[y1][x1];
    if (ret > origin)
        ret = origin;

    // 위쪽
    int temp = 0;
    for (int i = x1 + 1; i <= x2; ++i) {
        temp = origin;
        origin = arr[y1][i];
        arr[y1][i] = temp;
        if (ret > origin)
            ret = origin;
    }

    // 오른쪽
    for (int i = y1+1; i <= y2; ++i) {
        temp = origin;
        origin = arr[i][x2];
        arr[i][x2] = temp;
        if (ret > origin)
            ret = origin;
    }

    // 아래쪽
    for (int i = x2 - 1; i >= x1; --i) {
        temp = origin;
        origin = arr[y2][i];
        arr[y2][i] = temp;
        if (ret > origin)
            ret = origin;
    }

    // 왼쪽
    for (int i = y2 - 1; i >= y1; --i) {
        temp = origin;
        origin = arr[i][x1];
        arr[i][x1] = temp;
        if (ret > origin)
            ret = origin;
    }

    return ret;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    int count = 1;
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= columns; ++j) 
            arr[i][j] = count++;
    }

    for (auto a : queries) 
        answer.push_back(rotate(a[0], a[1], a[2], a[3]));

    return answer;
}

int main() {
    int rows = 6;
    int columns = 6;
    vector<vector<int>> queries = {{2, 2, 5, 4}, { 3, 3, 6, 6 }, { 5, 1, 6, 3 }};

    vector<int> ans = solution(rows, columns, queries);

    for (auto a : ans)
        cout << a << " ";

    return 0;
}

