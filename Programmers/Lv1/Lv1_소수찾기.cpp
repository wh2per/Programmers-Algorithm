#include <string>
#include <vector>
using namespace std;

int solution(int n) {
	vector<int> p(1000001);
	vector<bool> check(1000001);
	int pn = 0;
	int answer = 0;
	check[0] = check[1] = true;
	for (int i = 2; i*i <= n; i++) {
		if (check[i] == false) {
			p[pn++] = i;
			for (int j = i + i; j <= n; j += i)
				check[j] = true;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (check[i] == false)
			answer++;
	}

	return answer;	
}
