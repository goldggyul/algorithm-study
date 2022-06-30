// https://www.acmicpc.net/problem/20210
#include<string>
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> words;

string getDigitStartingFromIndex(int start, string str) {
    while (str[start] == '0') {
        start++;
    }
    int cnt = 0;
    for (int i = start; i < str.size(); i++) {
        if (isdigit(str[i])) {
            cnt++;
        } else {
            break;
        }
    }
    return str.substr(start, cnt);
}

int getNumberCnt(int start, string str) {
    int cnt = 0;
    for (int i = start; i < str.size(); i++) {
        if (isdigit(str[i])) {
            cnt++;
        } else {
            break;
        }
    }
    return cnt;
}
// true면 안바꿈, false면 바꿈
bool cmp(const string& o1, const string& o2) {
    int l = 0;
    int r = 0;
    while (l < o1.size() && r < o2.size()) {
        char left = o1[l];
        char right = o2[r];
        if (isdigit(left) && isdigit(right)) {
            // 둘다 숫자이므로 숫자를 끝까지 읽어야함
            string leftDigit = getDigitStartingFromIndex(l, o1);
            string rightDigit = getDigitStartingFromIndex(r, o2);
            if (leftDigit.size() > rightDigit.size()) {
                return false;
            } else if (leftDigit.size() < rightDigit.size()) {
                return true;
            } else {
                if (leftDigit > rightDigit) {
                    return false;
                } else if (leftDigit < rightDigit) {
                    return true;
                } else if (leftDigit == rightDigit) {
                    int leftStart = l;
                    int rightStart = r;
                    while (o1[leftStart] == '0') {
                        leftStart++;
                    }
                    while (o2[rightStart] == '0') {
                        rightStart++;
                    }
                    leftStart -= l;
                    rightStart -= r;
                    if (leftStart > rightStart) {
                        return false;
                    } else if (leftStart < rightStart) {
                        return true;
                    } else if (leftStart == rightStart) {
                        l += getNumberCnt(l, o1) - 1;
                        r += getNumberCnt(r, o2) - 1;
                    }
                }
            }
        } else  if (isdigit(left) && !isdigit(right)) {
            return true;
        } else  if (!isdigit(left) && isdigit(right)) {
            return false;
        } else  if (!isdigit(left) && !isdigit(right)) {
            // 둘이 같은 문자인데 대소문자가 다른 경우
            if (tolower(left) == tolower(right)) {
                if (islower(left) && isupper(right)) {
                    return false;
                } else if (isupper(left) && islower(right)) {
                    return true;
                }
            } else { // 둘이 다른 문자
                left = tolower(left);
                right = tolower(right);
                return left < right;
            }
        }
        l++; r++;
    }
    if (o1.size() > o2.size())
        return false;
    else if (o1.size() < o2.size())
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        words.push_back(s);
    }
    sort(words.begin(), words.end(), cmp);

    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << endl;
    }
    return 0;
}