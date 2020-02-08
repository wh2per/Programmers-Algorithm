#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long k) {
	vector<int> answer;
	list<int> l;
	vector<long long> factorial;
	factorial.push_back(1);

	for (int i = 0; i < n; i++) {
		l.push_back(i + 1);
		factorial.push_back(factorial[i] * (i + 1));
	}
	// ex) 4,10
	for (int i = n-1; i >=0; i--) {
		long long q = k/factorial[i];		// q = 10/6 = 1
		k = k % factorial[i];				// r = 10%6 = 4
		if (k == 0)
			q--;
		
		list<int>::iterator iter = l.begin();
		for (long long c = 0; c < q; c++)
			iter++;
		answer.push_back(*iter);
		l.erase(iter);
		
		if (k == 0) {
			list<int>::reverse_iterator iter(l.rbegin());
			for (; iter!= l.rend(); iter++)
				answer.push_back(*iter);
			break;
		}
	}
	
	return answer;
}
