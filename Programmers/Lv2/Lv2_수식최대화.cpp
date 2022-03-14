#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long cal(long long a, long long b, char op) {
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
}

long long solution(string expression) {
    long long answer = 0;

    vector<long long> nums;
    vector<char> oper;

    string temp = "";
    for (int i = 0; i < expression.length(); ++i) {
        if (isdigit(expression[i]))
            temp += expression[i];
        else {
            oper.push_back(expression[i]);
            nums.push_back(stoll(temp));
            temp = "";
        }
    }
    nums.push_back(stoll(temp));

    vector<int> order = { 0, 1, 2 };
    vector<char> ops = {'+', '-', '*'};
    do {
        vector<long long> temp_nums = nums;
        vector<char> temp_oper = oper;

        for (int i = 0; i < order.size(); i++) {
            for (int j = 0; j < temp_oper.size(); ) {
                if (temp_oper[j] == ops[order[i]]) {    // 내 순서에 맞춰서
                    long long ans = cal(temp_nums[j], temp_nums[j + 1], temp_oper[j]);

                    temp_nums.erase(temp_nums.begin() + j);
                    temp_nums.erase(temp_nums.begin() + j);
                    temp_nums.insert(temp_nums.begin() + j, ans);   // 2개 지우고 결과값 넣기

                    temp_oper.erase(temp_oper.begin() + j);  // 연산자 한개 지우기
                }
                else
                    j++;
            }
        }

        answer = max(answer, abs(temp_nums[0]));
    } while (next_permutation(order.begin(), order.end()));

    return answer;
}

int main() {
    cout << solution("100-200*300-500+20");
    return 0;
}