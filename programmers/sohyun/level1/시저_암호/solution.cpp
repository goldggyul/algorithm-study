#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ') continue;
        if(s[i] >= 'a'){
            if(s[i] + n > 'z') s[i] -= 26;
        }
        else if(s[i] >= 'A'){
            if(s[i] + n > 'Z') s[i] -= 26;
        }
        s[i] += n;
    }
    answer = s;
    return answer;
}