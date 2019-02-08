#include <string>
#include <stack>
using namespace std;

int solution96(string s)
{
	int answer = 1;
	stack<char> st;

	for (int i = 0; i < s.length(); i++) {
		if (st.empty() || st.top()!=s[i]) {
			st.push(s[i]);
		}
		else {
			st.pop();	
		}
	}

	if (st.empty())
		return 1;
	else
		return 0;

}
