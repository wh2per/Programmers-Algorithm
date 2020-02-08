#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;

typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;

Comparator compFunctor =
[](std::pair<std::string, int> elem1, std::pair<std::string, int> elem2)
{
	return elem1.second > elem2.second;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	multimap<string, pair<int,int>> m;
	map<string, int> sum;
	
	for (int i = 0; i < plays.size(); i++) {
		m.insert(make_pair(genres[i],make_pair(plays[i],i)));
		if (sum.find(genres[i]) != sum.end()) { 				// 안에 이미 있다면 
			int val = sum.find(genres[i])->second;
			sum.erase(sum.find(genres[i]));
			sum.insert(make_pair(genres[i], val + plays[i]));
		}
		else
			sum.insert(make_pair(genres[i], plays[i]));
	}
	set<pair<string, int>,Comparator> s(sum.begin(), sum.end(),compFunctor);

	for (auto si : s) {
		string sname = si.first;
		multimap<int, int,greater<int>> g;
		for (auto mi : m) {
			string name = mi.first;
			if (name == sname) 
				g.insert(mi.second);
		}
		map<int, int>::iterator it = g.begin();
		answer.push_back(it->second);
		if (g.size() > 1){
			it++;
			answer.push_back(it->second);
		}
	}
	return answer;
}
