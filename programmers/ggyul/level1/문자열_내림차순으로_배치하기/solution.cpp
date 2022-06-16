#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 큰 것부터 작은것, 대문자는 작은것
bool comp(char o1, char o2) {
    if (o1 >= 'A' && o2 >= 'A') {
        return o1 > o2;
    } else if (o1 >= 'A' && o2 <= 'z') {
        return false;
    } else if (o1 <= 'z' && o2 >= 'A') {
        return true;
    }
    return o1 > o2;
}

string solution(string s) {
    sort(s.begin(), s.end(), comp);
    return s;
}