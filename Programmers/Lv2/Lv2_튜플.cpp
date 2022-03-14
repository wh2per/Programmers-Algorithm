#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    s = s.substr(1, s.length() - 2);

    int idx = 0;
    map<int, set<int>> m;
    while (idx < s.length()) {
        set<int> tuple;
        int count = 0;
        string temp = "";
        while (idx++ < s.length()) {
            if (isdigit(s[idx]))
                temp += s[idx];
            else if (temp != "") {
                tuple.insert(stoi(temp));
                ++count;
                temp = "";
                if (s[idx] == '}') {
                    m.insert({ count, tuple });
                    break;
                }
            }
        }
    }

    set<int> ans;
    for (auto a : m) {
        for (auto b : a.second) {
            if (ans.count(b) == 0) {
                answer.push_back(b);
                ans.insert(b);
            }
        }
    }

    return answer;
}

int main() {
    vector<int> ans = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    for (auto a : ans)
        cout << a << " ";
 }