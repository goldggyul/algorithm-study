#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getCompressedCnt(string s, int unit) {
    string output;
    int pos = 0;
    while (pos < s.size()) {
        if (pos + unit >= s.size()) {
            output += s.substr(pos);
            break;
        }
        string str = s.substr(pos, unit);
        int cnt = 1;
        while (s.substr(pos + cnt * unit, unit) == str) {
            cnt++;
        }
        if (cnt == 1) {
            pos += unit;
            output += str;
        } else {
            pos += unit * cnt;
            output += to_string(cnt) + str;
        }
    }
    return output.size();
}

int solution(string s) {
    int answer = 1005;
    for (int i = 1; i <= s.size(); i++) {
        answer = min(answer, getCompressedCnt(s, i));
    }
    return answer;
}