#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int index;
bool compare(string a, string b) {
	if (a[index] == b[index])
		return a < b;
	else
		return a[index] < b[index];
}

vector<string> solution35(vector<string> strings, int n) {
	
	index = n;
	sort(strings.begin(), strings.end(), compare);

	return strings;
}
