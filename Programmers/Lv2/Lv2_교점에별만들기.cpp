#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<long long, long long>> cross;

    long long minX = LLONG_MAX, minY = LLONG_MAX;
    long long maxX = LLONG_MIN, maxY = LLONG_MIN;

    for (int i = 0; i < line.size() - 1; ++i) {
        long long a = line[i][0];
        long long b = line[i][1];
        long long e = line[i][2];
        for (int  j = i + 1; j < line.size(); ++j) {
            long long c = line[j][0];
            long long d = line[j][1];
            long long f = line[j][2];

            long long x1 = b * f - e * d;
            long long y1 = e * c - a * f;
            long long common = a * d - b * c;

            if (common == 0)
                continue;

            if (x1 % common == 0 && y1 % common==0) {
                long long ix = x1 / common;
                long long iy = y1 / common;

                if (maxX < ix)
                    maxX = ix;
                if (minX > ix)
                    minX = ix;
                if (maxY < iy)
                    maxY = iy;
                if (minY > iy)
                    minY = iy;
                cross.push_back({ ix, iy });
            }
        }
    }

    string s = "";
    for (long long j = 0; j <= maxX - minX; ++j)
        s += ".";

    for (long long i = 0; i <= maxY - minY; ++i)
        answer.push_back(s);

    for (auto a : cross)
        answer[a.second - minY][a.first - minX] = '*';

    reverse(answer.begin(), answer.end());
    return answer;
} 

int main() {
    vector<vector<int>> line = {{2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12}};
    vector<vector<int>> line1 = { {0, 1, -1},{1, 0, -1},{1, 0, 1 }};
    vector<string> answer = solution(line);
    for (auto a : answer)
        cout << a << endl;

    return 0;
}