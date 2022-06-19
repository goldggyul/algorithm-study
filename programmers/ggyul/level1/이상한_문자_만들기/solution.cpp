#include <string>
using namespace std;

string solution(string s) {
    bool isOdd = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            isOdd = false;
            continue;
        }
        if (isOdd && isupper(s[i])) {
            s[i] += 'a' - 'A';
        } else if (!isOdd && islower(s[i])) {
            s[i] += 'A' - 'a';
        }
        isOdd = !isOdd;
    }
    return s;
}