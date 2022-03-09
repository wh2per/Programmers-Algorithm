#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<int> arrA, vector<int> arrB) {
	if (arrA.size() != arrB.size())
		return false;
	else {
		for (int i = 0; i < arrA.size(); i++) {					// A 시작 위치
			for (int j = 0; j < arrA.size(); j++) {				// B 시작 위치
				int count = 0;
				for (int k = 0; k < arrA.size(); k++) {			// 검사시작
					int a = i + k;
					int b = j + k;
					if (a >= arrA.size())
						a -= arrA.size();
					if (b >= arrB.size())
						b -= arrB.size();
					if (arrA[a] != arrB[b])
						break;
					else
						count++;
				}
				if (count == arrA.size())
					return true;
			}
		}
	}
	return false;
}