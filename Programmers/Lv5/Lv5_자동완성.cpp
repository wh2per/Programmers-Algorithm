#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp_word(string a, string b) {
	return a.length() < b.length();
}

struct info_word {
	bool end;
	int depth;
	info_word *next_info[26];
};

int solution131(vector<string> words) {
	int answer = 0;
	info_word dic[26] = { {false,0,NULL}, };		// 모든 알파벳 초기화
	sort(words.begin(), words.end(), cmp_word);		// 짧은 순 정렬

	for (int i = 0; i < words.size(); ++i) {
		info_word *next = &dic[words[i][0]-'a'];	// 단어의 첫 알파벳을 루트로 시작

		for (int j = 0; j < words[i].size(); ++j) {		// 단어의 길이만큼 계속 info 생성해서 저장
			if (next->depth == 1)		// 이미 검색된 적 있으면
				++answer;

			next->depth++;
			if (next->depth > 1)		// 그 뒷 글자가 있다면
				answer++;

			if (next->end == true) {	// 마지막 글자였다면
				answer--;				// 그 전 글자를 쳤을 때 자동완성됨
				next->end = false;		
			}

			if (j == words[i].size() - 1) {		// 단어의 끝 글자라면
				if (next->depth == 1)
					next->end = true;
				break;
			}
			if (next->next_info[words[i][j + 1] - 'a'] == NULL) 		// 다음 글자 정보가 없다면
				next->next_info[words[i][j + 1] - 'a'] = new info_word({ 0,false,NULL });
			
			next = next->next_info[words[i][j + 1] - 'a'];
		}
	}

	return answer+words.size();
}
