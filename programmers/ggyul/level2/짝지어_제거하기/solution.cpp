// https://programmers.co.kr/learn/courses/30/lessons/12973
/*
투포인터인줄 알고 그걸로 풀어보다가
너무 어렵고 계속 틀려서 다시 처음부터 생각해보니 스택처럼 풀거같아서 스택으로 풀었더니 쉽게 맞음
좀 이상하면 다른 방법 생각해보기 ^^
*/
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