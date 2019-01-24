#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution83(vector<vector<int>> triangle) {
	int answer = triangle[0][0];

	if(triangle.size()==1)
		return answer;

	for (int i = 1; i < triangle.size(); i++) {			// 2 รþบฮลอ
		for (int j = 0; j <=i; j++) {
			if (j == 0) 
				triangle[i][j] += triangle[i - 1][j];
			else if (j == triangle[i].size()-1) 
				triangle[i][j] += triangle[i - 1][j-1];
			else 
				triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j-1]);
		}
	}

 	for (int i = 0; i < triangle.size(); i++) {
		if (answer < triangle[triangle.size() - 1][triangle.size() - 1 - i])
			answer = triangle[triangle.size() - 1][triangle.size() - 1 - i];
	}
	return answer;
} 

