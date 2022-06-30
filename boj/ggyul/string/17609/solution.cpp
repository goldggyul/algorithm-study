// https://www.acmicpc.net/problem/17609
#include <iostream>
#include <string>
using namespace std;

bool isPseudoPalindrome(string s, int left, int right) {
    while (left <= right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int left = 0;
        int right = s.size() - 1;
        bool jump = false;
        int ans = 0;
        while (left <= right) {
            if (s[left] != s[right]) {
                bool leftResult = isPseudoPalindrome(s, left + 1, right);
                bool rightResult = isPseudoPalindrome(s, left, right - 1);
                if (leftResult || rightResult) {
                    ans = 1;
                } else {
                    ans = 2;
                }
                break;
            }
            left++;
            right--;
        }
        cout << ans << endl;
    }
}