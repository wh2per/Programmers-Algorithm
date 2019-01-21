#include <string>
#include <vector>

using namespace std;

string solution56(string phone_number) {
	for (int i = phone_number.length() - 5; i >= 0; i--)
		phone_number[i] = '*';
	return phone_number;
}