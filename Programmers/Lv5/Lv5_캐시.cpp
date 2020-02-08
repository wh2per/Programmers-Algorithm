#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct cmp_cache {
	bool operator()(pair<string, int>& p1, pair<string, int>& p2) {
		if (p1.second > p2.second)
			return true;
		else 
			return false;
	}
};

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	int time = 0;
	if (cacheSize == 0)		// 사이즈가 0일때
		return cities.size() * 5;
	
	vector<pair<string, int>> cache;

	for (int i = 0; i < cities.size(); ++i) {
		// 모두 소문자로 변환
		for (int j = 0; j < cities[i].length(); ++j)
			cities[i][j] = tolower(cities[i][j]);
		
		bool flag = false;
		for (int j = 0; j < cache.size(); ++j) {
			cache[j].second++;
			if (cache[j].first == cities[i]) {
				cache[j].second = 0;
				++answer;
				flag = true;
			}
		}

		if(!flag){
			if (cache.size() < cacheSize) {		// 아직 캐시가 안 꽉참
				cache.push_back({ cities[i], 0 });
			}
			else {					// 캐시가 꽉찼으니 가장 안 쓰고 있는 것을 제거
				sort(cache.begin(), cache.end(), cmp_cache());
				cache[0] = { cities[i], 0 };
			}
			answer += 5;
		}
	}
		
	return answer;
}
