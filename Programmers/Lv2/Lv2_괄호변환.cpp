#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

bool isOk(string v) {
    stack<char> s;
    for (auto a : v) {
        if (s.size() > 0) {
            if (s.top() == '(' && a == ')')
                s.pop();
            else
                s.push(a);
        }
        else
            s.push(a);
    }

    if (s.size() != 0)
        return false;
    else
        return true;
}

string solution(string p) {
    string answer = "";
    // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
    if (p == "")
        return p;

    // 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
    string u = "";
    string v = "";

    int left = 0, right = 0;
    for (int i = 0; i < p.length(); ++i) {
        if (p[i] == '(')
            ++left;
        else
            ++right;
        
        if (left == right){
            u = p.substr(0,i+1);
            v = p.substr(i+1, p.length() - i - 1);
            break;
        }
    }

    if (isOk(u)) {  // 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
        if (v.length() == 0)
            return u;
        else {
            answer += u;        // 3 - 1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
            answer += solution(v);
        }
    }
    else {  // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
        string nv = "(";     // 4 - 1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
        nv += solution(v);     // 4 - 2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
        nv += ")";           // 4 - 3. ')'를 다시 붙입니다.
        string nu = u.substr(1, u.length() - 2);   // 4 - 4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
        for (auto a : nu) {
            if (a == '(')
                nv += ")";
            else
                nv += "(";
        }
        answer += nv;
    }
    // 4 - 5. 생성된 문자열을 반환합니다.
    return answer;
}

int main() {
    string p1 = "()))((()";
    string p2 = "(()())()";
    string p3 = ")(";
    cout << solution(p1);

    return 0;
}