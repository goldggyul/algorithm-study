#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    multiset<string> p; 
    for(int i = 0; i < participant.size(); i++){
        p.insert(participant[i]);
    }
    for(int i = 0 ; i < completion.size(); i++){
        auto it = p.find(completion[i]);
        p.erase(it);
    }
    auto it = p.begin();
    answer = *it;
    return answer;
}