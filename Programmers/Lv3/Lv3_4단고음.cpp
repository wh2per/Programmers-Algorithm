#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution95(int n) {
	int answer = 0;
	int sam = 1;
	long long end = 0;
	vector<long long> sum;
	sum.push_back(5);

	while (n > sum.back()) {
		long long asum = sum.back();
		asum *= 3;
		asum += 2;
		sum.push_back(asum);
		sam++;
	}
	end = sum.back();
	while (end >= n) {
		vector<char> arr;
		for (int i = sam * 2; i > 0; i--)
			arr.push_back('+');
		for (int i = sam; i > 0; i--)
			arr.push_back('*');
		if (sum.back() < n)
			return 0;
		do {
			long long pitch = 1;
			queue<char> q;
			vector<char> temp = arr;
			int i;
			int c = 0;
			for (i = temp.size() - 1; i >= 0; i--) {
				if (temp[i] != '+') {
					c -= 2;
					if (c < 0)
						break;
				}
				else
					c++;
			}

			if (i == -1) {				// 가능한 조합
				for (int j = 0; j < arr.size(); j++)
					q.push(arr[j]);

				while (!q.empty()) {
					char pc = q.front();
					q.pop();
					if (pc == '*')
						pitch *= 3;
					else
						pitch += 1;
				}

				if (pitch <= n) {
					end = pitch;
					if (end < n)
						break;
					else if (end == n)
						answer++;
				}
			}
		} while (prev_permutation(arr.begin(), arr.end()) && end >= n);		// 모든 조합
		sam--;
		sum.pop_back();
	}
	return answer;
}

int main() {
	cout << solution95(2147483647);
	return 0;
}

/*
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int dfs(int si,int sc,int n,int num,int jump,int start)
{
	if (si < 0) {
		if (num == n)return 1;
		return 0;
	}

	bool pos = false;
	int sum = 0;
	for (int j = si; j >= 0; j--)
	{
		sum += pow(3,j) * 2 * (start + jump + (si-j)*2);
		if (sum >= n - num)
			pos = true;
	}
	if (!pos)return 0;

	int r = 0;
	for (int i =start; i <=start+jump; i++)
	{
		int k = pow(3, si) * 2 * i;
		if (k > n - num)break;
		r += dfs(si - 1,sc,n,num+k,jump-(i-start)+2,i);
	}
	return r;
}
int solution(int n) {

	int answer = 0;
	int sc = 0;
	do {
		if (sc >=19)
			break;

		if (pow(3,sc+1) > n)
			break;
		else
			sc++;
	} while (true);
	int num = pow(3,sc) + sc*2;
	if (num == n)
		return 1;
	answer=dfs(sc-2, sc, n, num, 2,0);
	return answer;
}
*/
