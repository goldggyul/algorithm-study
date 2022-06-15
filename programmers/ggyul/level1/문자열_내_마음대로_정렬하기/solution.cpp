// https://programmers.co.kr/learn/courses/30/lessons/12915
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int target;

bool comp(string o1, string o2) {
    if (o1[target] == o2[target]) {
        return o1 < o2;
    }
    return o1[target] < o2[target];
}

vector<string> solution(vector<string> strings, int n) {
    target = n;
    sort(strings.begin(), strings.end(), comp);
    return strings;
}