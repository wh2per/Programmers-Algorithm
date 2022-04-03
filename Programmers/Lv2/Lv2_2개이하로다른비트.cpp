#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (auto a : numbers) {
        if (a % 2 == 0) {  // 짝수
            answer.push_back(a + 1);
        }
        else { // 홀수
            long long last = (a + 1) & -a;      //  1101 -> 1110 & 0011 = 0010 
            answer.push_back((a | last) & ~(last >> 1));   // (1101 | 0010) & ~(0001) = 1111 & 1110 = 1110
        }
    }
    return answer;
}

int main() {
    vector<long long> answer = solution({ 2,7 });
    for (auto a : answer)
        cout << a << " ";
    return 0;
}