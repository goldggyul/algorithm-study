// https://programmers.co.kr/learn/courses/30/lessons/12973
#include <iostream>
#include <vector>
#include<string>
using namespace std;

int solution(string s)
{
    int answer = 1;
    vector<char> v;
    for (int i = 0; i < s.size(); i++) {
        if (v.size() > 0) {
            if (v.back() == s[i]) {
                v.pop_back();
            } else {
                v.push_back(s[i]);
            }
        } else {
            v.push_back(s[i]);
        }
    }
    if (v.size() > 0)
        answer = 0;
    return answer;
}