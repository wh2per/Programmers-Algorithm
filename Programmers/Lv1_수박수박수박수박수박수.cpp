#include <string>
#include <vector>

using namespace std;

string solution41(int n) {
	string answer = "";
	string a = "¼ö¹Ú";
	string b = "¼ö";
	
	for (int i = 0; i < n / 2; i++)
		answer+=a;
	if (n % 2 == 1)
		answer += b;

	return answer;
}