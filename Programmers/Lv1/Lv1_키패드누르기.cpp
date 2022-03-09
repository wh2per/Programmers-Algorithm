#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dist[13][13];


string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;
    int right = 12;

    dist[1][2] = dist[3][2] = dist[4][5] = dist[6][5] = dist[7][8] = dist[9][8] = dist[10][11] = dist[12][11] = 1;
    dist[1][5] = dist[3][5] = dist[4][2] = dist[4][8] = dist[6][2] = dist[6][8] = dist[7][5] = dist[9][5] = dist[7][11] = dist[9][11] = dist[10][8] = dist[12][8] = 2;
    dist[1][8] = dist[3][8] = dist[4][11] = dist[6][11] = dist[7][2] = dist[9][2] = dist[10][5] = dist[12][5] = 3;
    dist[1][11] = dist[3][11] = dist[10][2] = dist[12][2] = 4;

    for (auto a : numbers) {
        if (a == 1 || a == 4 || a == 7) {
            answer += "L";
            left = a;
        }
        else if(a == 3 || a == 6 || a == 9) {
            answer += "R";
            right = a;
        }else{
            int number = a;
            if (number == 0) 
                number = 11;

            int left_diff = 0;
            int right_diff = 0;

            // 왼손과의 거리
            if (left == 2 || left == 5 || left == 8 || left == 11) 
                left_diff = abs(number - left) / 3;
            else 
                left_diff = dist[left][number];
            

            // 오른손과의 거리
            if (right == 2 || right == 5 || right == 8 || right == 11)
                right_diff = abs(number - right) / 3;
            else 
                right_diff = dist[right][number];
            
            
            if (left_diff < right_diff) {
                answer += "L";
                left = number;
            }
            else if (left_diff > right_diff) {
                answer += "R";
                right = number;
            }
            else {
                if (hand == "left") {
                    answer += "L";
                    left = number;
                }
                else {
                    answer += "R";
                    right = number;
                }
            }
        }
    }

    return answer;
}

int main() {
    vector<int> arr = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string hand = "right";

    cout << solution(arr, hand);
    return 0;
}