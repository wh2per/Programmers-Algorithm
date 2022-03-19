

int main() {
    cout << solution("[](){}");
    cout << solution("}]()[{");
    cout << solution("[)(]");
    return 0;
}#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool check(string s) {
    stack<char> st;
    bool flag = false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            st.push('(');
        else if (s[i] == '{')
            st.push('{');
        else if (s[i] == '[')
            st.push('[');
        else
        {
            if (!st.empty()) {
                flag = true;
                if (st.top() == '(' && s[i] == ')')
                    st.pop();
                else if (st.top() == '{' && s[i] == '}')
                    st.pop();
                else if (st.top() == '[' && s[i] == ']')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
    }
    if (st.empty() && flag)
        return true;
    else
        return false;
}

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.length(); ++i) {
        s += s[0];
        s = s.substr(1, s.length() - 1);

        if (check(s))
            ++answer;
    }

    return answer;
}