#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

struct info_music {
	string name;
	string sheet;
	int time;
	int num;
};

struct cmp_music {
	bool operator()(info_music im1, info_music im2) {
		if (im1.time > im2.time)
			return true;
		else if (im1.time == im2.time) {
			if (im1.num < im2.num)
				return true;
			else
				return false;
		}
		else
			return false;
	}
};

string change_music(string music) {
	string temp = "";
	int i;
	for (i = 0; i < music.length()-1; ++i) {
		if (music[i + 1] != '#')
			temp += music[i];
		else {
			if (music[i] == 'C') {
				temp += "H";
				++i;
			}
			else if (music[i] == 'D') {
				temp += "I";
				++i;
			}
			else if (music[i] == 'F') {
				temp += "J";
				++i;
			}
			else if (music[i] == 'G') {
				temp += "K";
				++i;
			}
			else if (music[i] == 'A') {
				temp += "L";
				++i;
			}
		}
	}
	if (music[music.length() - 1] != '#')
		temp += music[music.length() - 1];
	return temp;
}

string solution129(string m, vector<string> musicinfos) {
	vector<info_music> v;
	int num = 0;
	for (int i = 0; i < musicinfos.size(); ++i) {
		string s,text=musicinfos[i];
		stringstream ss(text);
		vector<string> info;
		while (getline(ss,s,',')) 
			info.push_back(s);

		int start = atoi(info[0].substr(0, 2).c_str())*60 + atoi(info[0].substr(3, 2).c_str());
		int end = atoi(info[1].substr(0, 2).c_str()) * 60 + atoi(info[1].substr(3, 2).c_str());
		int time_diff = end - start;

		string temp = change_music(info[3]);
		string sheet = "";
		if (time_diff > temp.length()) {			// 재생시간 > 악보길이
			int cycle = time_diff / temp.length();
			for (int j = 0; j < cycle; ++j) {
				for (int k = 0; k < temp.length(); ++k) 
					sheet += temp[k];
			}

			int left = time_diff - (temp.length()*cycle);
			for (int k = 0; k < left; ++k) 
				sheet += temp[k];
		}
		else {									// 재생시간 <= 악보길이
			for (int j = 0; j < time_diff; ++j)
				sheet += temp[j];
		}

		v.push_back({info[2],sheet,time_diff,num++});
	}

	// 음악을 찾자!
	vector<info_music> ans;
	string f = change_music(m);
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].sheet.find(f) != v[i].sheet.npos) 
			ans.push_back(v[i]);
	}

	if (ans.size() == 0)
		return "(NONE)";
	else {
		sort(ans.begin(), ans.end(), cmp_music());
		return ans[0].name;
	}
}
