#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <regex>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct user {
    string code;
    int score;
};

user users[50001];
vector<string> candidates;
unordered_map<string, pair<int, int>> m;

const string ops[4][3] = { {"java", "python", "cpp"}, {"frontend","backend"},{"junior","senior"},{"pizza","chicken"}};

bool cmp(user &u1, user &u2) {
    if (u1.code < u2.code)
        return true;
    else if (u1.code == u2.code) {
        if (u1.score < u2.score)
            return true;
        else
            return false;
    }
    else
        return false;
}

void getCandidate(string s[], string code, int idx){
    if (idx > 3) {
        candidates.push_back(code);
        return;
    }

    if (s[idx] != "-") {
        getCandidate(s, code + s[idx], idx + 1);
    }
    else {
        int end = 2;
        if (idx == 0)
            end = 3;
        for (int i = 0; i < end; ++i) 
            getCandidate(s, code + ops[idx][i], idx + 1);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    int row = info.size();

    for (int i = 0; i < info.size(); ++i) {
        string s[5];
        istringstream sst(info[i]);
        sst >> s[0] >> s[1] >> s[2] >> s[3] >> s[4];

        string code;
        for (int i = 0; i < 4; ++i)
            code += s[i];

        users[i] = {code, stoi(s[4])};
    }

    sort(users, users + row, cmp);
    int s=0, e=0;
    string prev = users[0].code;
    for (int i = 0; i < row; ++i) {
        if (prev != users[i].code) {
            e = i - 1;
            if(e!=-1)
                m.insert({ prev, { s,e } });

            prev = users[i].code;
            s = i;
            e = i;
        }
    }
    m.insert({ prev, { s,row-1 } });

    for (auto a : query) {
        string b = regex_replace(a,regex("and "),"");
        string s[5];
        istringstream sst(b);
        sst >> s[0] >> s[1] >> s[2] >> s[3] >> s[4];

        candidates.clear();
        getCandidate(s, "", 0);

        int count = 0;
        int want = stoi(s[4]);

        for (auto b : candidates) {
            if (m.count(b) > 0) {
                pair<int, int> pos = m[b];
                int left = pos.first;
                int right = pos.second;
                int mid, lower_bnd=-1;

                while (left <= right){
                    mid = (left + right) >> 1;
                    if (users[mid].score >= want){
                        lower_bnd = mid;
                        right = mid - 1;
                    }
                    else left = mid + 1;
                }
                if(lower_bnd!=-1)
                    count += pos.second-lower_bnd+1;
                
            }
        }

        answer.push_back(count);
    }

    return answer;
}

int main() {
    vector<string> info = { "java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50" };
    vector<string> query = { "java and backend and junior and pizza 100", "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150" };
    vector<int> answer = solution(info, query);

    for (auto a : answer)
        cout << a << " ";
    return 0;
}