// https://school.programmers.co.kr/learn/courses/30/lessons/60058
#include <string>
#include <vector>
using namespace std;

bool checkBracket(string p, bool isRight) {
    int left_cnt = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') {
            left_cnt++;
        } else if (p[i] == ')') {
            if (isRight && left_cnt == 0) {
                return false;
            } else {
                left_cnt--;
            }
        }
    }
    return (left_cnt == 0);
}

string recursive(string p) {
    if (p.size() == 0 || checkBracket(p, true)) return p;
    // 2. 문자열 분리
    string u = p.substr(0, 2);
    int target = 2;
    while (target < p.size() && !checkBracket(u, false)) {
        u += p[target];
        target++;
    }
    string v = p.substr(target, p.size());
    // 3. 문자열 u가 올바른 괄호 문자열인가?
    if (checkBracket(u, true)) {
        return u + recursive(v);
    } else {
        string result = "(";
        result += recursive(v);
        result += ")";
        u.erase(0, 1);
        u.erase(u.size() - 1, 1);
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == ')') {
                result += '(';
            } else if (u[i] == '(') {
                result += ')';
            }
        }
        return result;
    }
}

string solution(string p) {
    return recursive(p);
}