#include <string>
#include <vector>
#include <iostream>
#include <regex>
using namespace std;

int solution(string s) {
    int answer = 0;
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");
    answer = stoi(s);
    return answer;
}

int main() {
    string s = "one4oneeight";
    cout << solution(s);
    return 0;
}