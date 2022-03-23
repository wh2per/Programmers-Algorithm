#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    int size = (n * (n + 1)) / 2;
    vector<int> answer(size,0);
    
    int idx = 0;
    int cnt = 1;
    int dir = 1;
    int origin = n;
    int cycle = 0;

    answer[0] = 1;
    for (int i = 2; i <= size; ++i) {
        if (cnt  < n) {
            if (dir % 3 == 1) {
                idx += cnt+cycle;
            }
            else if (dir % 3 == 2) {
                ++idx;
            }
            else {
                idx -= (origin-cnt);
            }
            ++cnt;
        }
        else {
            if (dir % 3 != 2)
                ++cycle;
            ++dir;
            if (dir % 3 == 1)
                --origin;
            --n;
            cnt = 0;
            --i;
            continue;
        }
        answer[idx] = i;
    }

    return answer;
}

int main() {
    vector<int> answer = solution(6);

    for (auto a : answer)
        cout << a << " ";

    return 0;
}