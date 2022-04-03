#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    int ln = left / n;
    int lm = left % n;
    int rn = right / n;
    int rm = right % n;

    // 왼쪽
    if (ln != rn) {
        for (int i = lm + 1; i <= n; ++i) {
            if (i < ln + 1)
                answer.push_back(ln + 1);
            else
                answer.push_back(i);
        }

        // 중간
        for (int i = ln + 1; i < rn; ++i) {
            for (int k = 0; k < i + 1; ++k)
                answer.push_back(i + 1);
            for (int j = i + 2; j <= n; ++j)
                answer.push_back(j);
        }

        // 오른쪽
        for (int i = 0; i <= rm; ++i) {
            if (i < rn + 1)
                answer.push_back(rn + 1);
            else
                answer.push_back(i + 1);
        }
    }
    else {
        for (int i = lm; i <= rm; ++i) {
            if (i < rn + 1)
                answer.push_back(rn + 1);
            else
                answer.push_back(i + 1);
        }
    }

    return answer;
}

int main() {
    vector<int> ans = solution(4,4,7);
    for (auto a : ans)
        cout << a << " ";
    return 0;
}