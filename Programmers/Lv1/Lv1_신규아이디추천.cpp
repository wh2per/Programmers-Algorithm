#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";

    for (int i = 0; i < new_id.length(); ++i) {
        // 1�ܰ�
        new_id[i] = tolower(new_id[i]);
        
        // 2�ܰ�
        if ((new_id[i] >= 48 && new_id[i] <= 57) || (new_id[i] >= 97 && new_id[i] <= 122) || new_id[i]==45 || new_id[i]==95)
            answer += new_id[i];
        else if (new_id[i] == 46) { // 3�ܰ�
            if(i==0 || (i>0 && answer[answer.length()-1] != 46))
                answer += new_id[i];
        }
    }

    // 4�ܰ�
    if (answer[0] == 46)
        answer = answer.substr(1, answer.length() - 1);
    if (answer[answer.length() - 1] == 46)
        answer = answer.substr(0, answer.length() - 1);

    // 5�ܰ�
    if (answer.length() == 0)
        answer += "a";

    // 6�ܰ�
    if (answer.length() > 15)
        answer = answer.substr(0, 15);
    if (answer[answer.length() - 1] == 46)
        answer = answer.substr(0, answer.length() - 1);

    // 7�ܰ�
    while (answer.length() < 3) 
        answer += answer[answer.length()-1];
    
    return answer;
}

int main() {
    string s = "-.~!@#$%&*()=+[{]}:?,<>/.-";
    cout << solution(s);

    return 0;
}