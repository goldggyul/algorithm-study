#include <string>

using namespace std;

int solution(string s) {
    int answer = s.size();
    string str = "";
    for(int i = 1; i <= s.size(); i++){
        int cnt = 1;
        bool isSame = false;
        for(int j = 0; j < s.size(); j+=i){
            if(j+i < s.size()){
                if(s.substr(j,i) == s.substr(j+i,i)){
                    cnt++;
                    isSame = true;
                }else{
                    if(isSame){
                        str += to_string(cnt) + s.substr(j,i);
                        isSame = false;
                    }
                    else    str += s.substr(j,i);
                    cnt = 1;
                }
            }
            if(j+i >= s.size()){
                if(isSame)  str += to_string(cnt) + s.substr(j,i);
                else    str += s.substr(j,i);
            }
        }
        if(answer > str.size()){
            answer = str.size();
        }
        str = "";
    }
    
    return answer;
}