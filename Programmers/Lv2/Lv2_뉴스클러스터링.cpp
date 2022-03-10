#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    string s1 = "", s2 = "";

    for (int i = 0; i < str1.length(); ++i) 
        str1[i] = tolower(str1[i]);
    
    for (int i = 0; i < str2.length(); ++i) 
        str2[i] = tolower(str2[i]);

    map<string, int> m1, m2;
    for (int i = 0; i < str1.length()-1; ++i) {
        string s = str1.substr(i,2);
        if (isalpha(s[0]) && isalpha(s[1])) {
            if (m1.count(s) > 0)
                m1[s]++;
            else
                m1.insert({ s,1 });
        }
    }

    for (int i = 0; i < str2.length()-1; ++i) {
        string s = str2.substr(i, 2);
        if (isalpha(s[0]) && isalpha(s[1])) {
            if (m2.count(s) > 0)
                m2[s]++;
            else
                m2.insert({ s,1 });
        }
    }

    float f1 = 0, f2 = 0;
    // 합집합 찾기
    for (auto a : m1)
        f2 += a.second;
    for (auto b : m2)
        f2 += b.second;

    // 교집합찾기
    for (auto a : m1) {
        for (auto b : m2) {
            if (a.first == b.first) {
                f1 += min(a.second, b.second);
                f2 -= min(a.second, b.second);
            }
        }
    }
    
    if (f1 == 0 && f2 == 0)
        return 65536;
    else
        answer = f1 / f2 * 65536;

    return answer;
}

int main() {
    cout << solution("FRANCE", "french");
    return 0;
}