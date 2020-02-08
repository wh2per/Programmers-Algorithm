#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> answer102;
void hanoi(int n, int from, int by, int to)			// 1.재귀함수 이용
{
	if (n == 1)
	{
		vector<int> v;			
		v.push_back(from);
		v.push_back(to);
		answer102.push_back(v);
		return;
	}

	hanoi(n - 1, from, to, by); // n-1 개의 원판을 1에서 3을 이용하여 2로 옮긴다.
	vector<int> v;
	v.push_back(from);
	v.push_back(to);
	answer102.push_back(v);
	hanoi(n - 1, by, from, to); // n-1개의 원판을 2에서 1을 이용하여 3으로 옮긴다.
}

vector<vector<int>> solution(int n) {
	//hanoi(n, 1, 2, 3);
	stack<int> s;							// 2. 비재귀 
	int from = 1;
	int by = 2;
	int to = 3;
	while (1){
        while (n > 1){
            s.push(to);    // 인자리스트 푸쉬
            s.push(by);
            s.push(from);
            s.push(n);
            n--;        // 인자리스트 변경 1
            s.push(to);    // to 와 by를 교환하기 위해 임시로 저장
            to = by;
            by = s.top();
			s.pop();
        }

		vector<int> v;
		v.push_back(from);
		v.push_back(to);
		answer102.push_back(v);

        if (!s.empty()){
            n = s.top();
			s.pop();
            from = s.top();
			s.pop();
            by = s.top();
			s.pop();
            to = s.top();
			s.pop();

			vector<int> v;
			v.push_back(from);
			v.push_back(to);
			answer102.push_back(v);

            n--;        // 인자리스트 변경 2
            s.push(from);
            from = by;
            by = s.top();
			s.pop();
        }
        else{
            break;
        }
    }

	return answer102;
}
