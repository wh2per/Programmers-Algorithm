#include <string>
#include <vector>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<bool> check(true,10);

    for (auto a : numbers)
        check[a] = false;

    for (int i = 1; i < 10; ++i) {
        if (check[i])
            answer += i;
    }

    return answer;
}
