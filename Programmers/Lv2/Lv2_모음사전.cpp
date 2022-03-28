#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> words;
const string w[] = {"A","E","I","O","U"};

bool cmp(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    if (len1 < len2) {
        for (int i = 0; i < len1; ++i) {
            if (s1[i] < s2[i])
                return true;
            else if (s1[i] == s2[i])
                continue;
            else
                return false;
        }
        return true;
    }
    else if (len1 == len2) {
        for (int i = 0; i < len1; ++i) {
            if (s1[i] < s2[i])
                return true;
            else if (s1[i] == s2[i])
                continue;
            else
                return false;
        }
    }
    else {
        for (int i = 0; i < len2; ++i) {
            if (s1[i] < s2[i])
                return true;
            else if (s1[i] == s2[i])
                continue;
            else
                return false;
        }
        return false;
    }

    return true;
}

void insertString(string s, int cnt, int goal) {
    if (cnt == goal) {
        words.push_back(s);
        return;
    }

    for (int i = 0; i < 5; ++i) {
       insertString(s+w[i], cnt + 1, goal);
    }
}

int solution(string word) {
    int answer = 0;

    for (int i = 1; i <= 5; ++i) 
        insertString("", 0, i);

    sort(words.begin(), words.end(), cmp);

    for (int i = 0; i < words.size(); ++i) {
        if (words[i] == word) {
            answer = i + 1;
            break;
        }
    }

    return answer;
}

int main() {
    cout << solution("AAAAE");
    return 0;
}