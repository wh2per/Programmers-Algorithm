#include <algorithm>
#include <vector>
using namespace std;

int solution105(vector<int> A, vector<int> B) {
	int answer = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int save = 0;
	
	for (int i = 0; i < A.size(); i++) {
		for (int j = save; j < B.size(); j++) {
			if(A[i]<B[j]){
				answer++;
				save = j;
				save++;
				break;
			}
		}
	}
	return answer;
}
