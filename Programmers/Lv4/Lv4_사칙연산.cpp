#include <vector>
#include <string>
#include <climits>
using namespace std;

int solution(vector<string> arr)
{
	vector < vector<vector<int>>> d(201,vector<vector<int>>(201,vector<int>(2,0)));
	int len = arr.size();
	int tmax, tmin, max, min;

	// 숫자로 변환
	for (int i = 0; i < len; i+=2) {
		d[i][i][0] = stoi(arr[i]);
		d[i][i][1] = stoi(arr[i]);
	}

	for (int i = 2; i < len; i += 2) {		// 첫 숫자, 연산자 이후로 끝까지 (숫자, 연산자) 세트로 증가	-> 범위의 종료 지점 설정
		for (int j = 0; j+i < len; j += 2) {		// 처음부터 len-i 길이를 전부 검사					-> 범위의 시작 시점 부터 종료 지점까지 검사
			tmax = 0;
			tmin = 0;
			max = INT_MIN;
			min = INT_MAX;
			for (int k = j+1; k < i + j; k+=2) {		// 연산 시작	
				if (arr[k] == "+") {				// +
					tmax = d[j][k - 1][0] + d[k + 1][i + j][0];
					tmin = d[j][k - 1][1] + d[k + 1][i + j][1];
					if (tmax > max)
						max = tmax;
					if (tmin < min)
						min = tmin;
				}
				else if (arr[k] == "-") {			// -
					tmax = d[j][k - 1][0] - d[k + 1][i + j][1];
					tmin = d[j][k - 1][1] - d[k + 1][i + j][0];
					if (tmax > max)
						max = tmax;
					if (tmin < min)
						min = tmin;
				}
			}
			d[j][j + i][0] = max;
			d[j][j + i][1] = min;
		}
	}
	return d[0][len - 1][0];
}