#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool Comp(const string& a, const string& b)
{
	if (a == b) return false;

	string ab = a + b;
	string ba = b + a;

	if (ab > ba) return true;		
	else return false;
}


string solution15(vector<int> numbers) {
	string answer = "";
	int zero = 0;
	vector<string> temp;

	for (auto i : numbers)
	{
		if (i == 0) 
			++zero;
		temp.push_back(to_string(i));
	}

	// 000 °æ¿ì
	if (zero == numbers.size()) return "0";

	sort(temp.begin(), temp.end(), Comp);

	for (auto s : temp) answer.append(s);

	return answer;
}
