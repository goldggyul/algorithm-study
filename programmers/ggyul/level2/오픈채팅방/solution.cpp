// https://programmers.co.kr/learn/courses/30/lessons/42888
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> idToName;
    for (int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        string op;
        ss >> op;
        if (op == "Enter" || op == "Change") {
            string id, nickName;
            ss >> id >> nickName;
            idToName[id] = nickName;
        }
    }
    for (int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        string op, id;
        ss >> op >> id;
        if (op == "Enter") {
            answer.push_back(idToName[id] + "님이 들어왔습니다.");
        } else if (op == "Leave") {
            answer.push_back(idToName[id] + "님이 나갔습니다.");
        }
    }
    return answer;
}