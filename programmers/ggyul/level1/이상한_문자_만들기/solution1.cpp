#include <string>
using namespace std;

string solution(string s) {
    bool isOdd = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            isOdd = false;
            continue;
        }
        if (isOdd) {
            s[i] = tolower(s[i]);
        } else if (!isOdd) {
            s[i] = toupper(s[i]);
        }
        isOdd = !isOdd;
    }
    return s;
}