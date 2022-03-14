#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; ++i) {
        int count=0;
		for (int j = 1; j <= i; j++){
			if (i % j == 0)		//모듈러 연산의 값이 0, 즉 나누어 떨어진다면
				++count;			//약수라고 판단하고 약수의 개수를 +1 해준다
		}

        if (count % 2 == 0) 
            answer += i;
        else
            answer -= i;
    }

    return answer;
}