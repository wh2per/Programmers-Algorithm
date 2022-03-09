#include <string>
#include <vector>
#include <set>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	multiset<string> s;

	multiset<string>::iterator it;
	int ptcpt_size = participant.size();

	for (int i = 0; i < ptcpt_size; i++)
		s.insert(participant[i]);

	for (int i = 0; i < ptcpt_size - 1; i++) {
		it = s.find(completion[i]);
		s.erase(it);
	}

	it = s.begin();
	answer = *it;

	return answer;
}