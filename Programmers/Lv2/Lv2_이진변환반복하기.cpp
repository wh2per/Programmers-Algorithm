#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string digit(int n) {
    string s = "";
    while (n != 0) {
        s = s+ to_string(n % 2);
        n /= 2;
    }
    return s;
}

int countZero(string s) {
    int ret = 0;
    for (auto a : s) {
        if (a == '0')
            ++ret;
    }
    return ret;
}

vector<int> solution(string s) {
    vector<int> answer;

    int cnt=0,zcnt = 0;
    int round = 0;

    do {
        zcnt = countZero(s);
        cnt += zcnt;
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        s = digit(s.length());
        ++round;
    } while (s != "1");
    
    answer.push_back(round);
    answer.push_back(cnt);

    return answer;
}

int main() {
    vector<int> ans = solution("01110");
    for (auto a : ans)
        cout << a << " ";
    return 0;
}