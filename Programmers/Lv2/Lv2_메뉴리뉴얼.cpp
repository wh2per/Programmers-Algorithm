#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;

void combination(string s, int len) {
    vector<bool> check(s.length(), true);
    for (int i = 0; i < len; ++i)
        check[i] = false;

    do {
        string menu = "";
        for (int i = 0; i < s.length(); ++i) {
            if (!check[i])
                menu += s[i];
        }

        if (m.count(menu) > 0)
            m[menu]++;
        else
            m.insert({ menu,1 });
    } while (next_permutation(check.begin(), check.end()));
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (auto a : orders) {
        for (auto b : course) {
            if (a.length() >= b) {     // 시킨 메뉴갯수가 코스메뉴 갯수 이상이면?
                sort(a.begin(), a.end());
                combination(a, b);
            }
        }
    }
    for (auto b : course) {     // 메뉴 갯수
        vector<pair<string, int>> ans;

        for (auto a : m) {      // 메뉴
            if (a.first.length() < b)
                continue;
            if (a.first.length() == b && a.second >= 2) {
                if(ans.size() == 0 || a.second == ans[0].second)
                    ans.push_back(a);
                else if(ans.size()>0 && a.second > ans[0].second) {
                    ans.clear();
                    ans.push_back(a);
                }
            }
        }

        for (auto c : ans)
            answer.push_back(c.first);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    vector<string> orders = { "XYZ", "XWY", "WXA" };
    vector<int> course = { 2,3,4 };

    vector<string> ans = solution(orders, course);

    for (auto a : ans)
        cout << a << " ";

    return 0;
}