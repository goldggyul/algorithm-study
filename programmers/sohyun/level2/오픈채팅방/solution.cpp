#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> user;
    vector<pair<string, string>> message;
    
    for(int i = 0; i < record.size(); i++){
        istringstream ss(record[i]);
        string tmp;
        vector<string> str;
        while(getline(ss,tmp,' ')){
            str.push_back(tmp);
        }
        if(str[0] == "Enter" || str[0] == "Change"){
            user[str[1]] = str[2];
        }
        if(str[0] != "Change")
            message.push_back(make_pair(str[0], str[1]));
    }
    
    for(int i = 0; i < message.size(); i++){
        string m;
        if(message[i].first == "Enter")
            m = user[message[i].second] + "님이 들어왔습니다.";
        
        if(message[i].first == "Leave")
            m = user[message[i].second] + "님이 나갔습니다.";
            
        answer.push_back(m);
    }
    
    return answer;
}