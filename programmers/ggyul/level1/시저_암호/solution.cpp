#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ')continue;
        if (s[i] <= 'Z' && s[i] + n > 'Z') {
            s[i] = 'A' + n - ('Z' - s[i] + 1);
        } else if (s[i] <= 'z' && s[i] + n > 'z') {
            s[i] = 'a' + n - ('z' - s[i] + 1);
        } else {
            s[i] += n;
        }
    }
    return s;
}