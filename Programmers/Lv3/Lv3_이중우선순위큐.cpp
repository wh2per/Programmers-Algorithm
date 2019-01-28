#include <string>
#include <vector>
#include <list>
#include <sstream>
using namespace std;

vector<int> solution77(vector<string> operations) {
	vector<int> answer;
	list<int> l;
	
	for (int i = 0; i < operations.size(); i++) {
		stringstream split_string(operations[i]);
		string oper;
		string num;
		int real_num = 0;
		split_string >> oper;
		split_string >> num;
		if (oper == "I") {
			if (num[0] == '-')
				real_num -= atoi(num.substr(1, num.length()).c_str());
			else
				real_num += atoi(num.c_str());
			l.push_back(real_num);
			l.sort();
		}
		else {
			if (num == "1") {			// ÃÖ´ñ°ª »èÁ¦ 
				if(l.size()>0)
					l.pop_back();
			}
			else {						// ÃÖ¼Ú°ª »èÁ¦ 
				if (l.size() > 0)
					l.pop_front();
			}
		}
	}

	if (l.size()==0) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(l.back());
		answer.push_back(l.front());
	}
		
	return answer;
}
