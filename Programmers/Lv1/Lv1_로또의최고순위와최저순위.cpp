#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool check[46];

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int count = 0;
    int zero = 0;

    for (auto a : lottos) {
        check[a] = true;
        if (a == 0)
            ++zero;
    }

    for (auto a : win_nums) {
        if (check[a])
            ++count;
    }

    int min = 7 - count;
    if (min == 7)
        min = 6;

    int max = 7 - (count + zero);
    if (max == 7)
        max = 6;

    answer.push_back(max);
    answer.push_back(min);
    return answer;  
}

int main() {
    vector<int> lottos = { 1,2,3,4,5,6 };
    vector<int> win_nums = { 7,8,9,10,11,12 };

    vector<int> ans = solution(lottos, win_nums);

    for (auto a : ans)
        cout << a << " ";

    return 0;
}