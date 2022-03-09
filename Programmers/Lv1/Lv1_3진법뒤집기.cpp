#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> three;

    while (n){
        three.push_back(n % 3);
        n /= 3;
    }
    reverse(three.begin(), three.end());

    for (int i = 0; i < three.size(); ++i)
        answer += pow(3, i) * three[i];

    return answer;
}