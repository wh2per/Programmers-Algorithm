#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    set<string> n_report;
    map<string, int> m;

    int index = 0;
    for (auto a : id_list) {
        m.insert({ a,index++ });
    }

    vector<vector<int>> info(id_list.size(), vector<int>());
    vector<int> check(id_list.size(), 0);

    for (auto a : report)
        n_report.insert(a);

    for (auto a : n_report) {
        string s1, s2;
        stringstream stream;
        stream.str(a);

        stream >> s1;
        stream >> s2;

        check[m[s2]]++;                     // 신고당한 사람 횟수 증가 
        info[m[s2]].push_back(m[s1]);       // 누가 신고했는지 저장 (알림용)
    }

    for (int i = 0; i < check.size(); i++) {
        if (check[i] >= k) {
            for (auto a : info[i])
                answer[a]++;
        }
    }
        
    return answer;
}

int main() {
    vector<string> list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = { "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" };
    int k = 2;

    vector<int> ans = solution(list, report, k);

    for (auto a : ans)
        cout << a << endl;

    return 0;
}