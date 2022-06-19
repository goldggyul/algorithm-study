#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    string word = "";
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' '){
            word += s[i];
        }
        else if(s[i] == ' '){
            if(!word.empty()){
                for(int j = 0; j < word.size(); j++){
                    if(j % 2 == 0)  word[j] = toupper(word[j]);
                    else word[j] = tolower(word[j]);
                }
            }
            answer += word;
            answer += " ";
            word = "";
        }
        if(i == s.size()-1){
            for(int j = 0; j < word.size(); j++){
                if(j % 2 == 0)  word[j] = toupper(word[j]);
                else word[j] = tolower(word[j]);
            }
            answer += word;
        }
    }
    return answer;
}