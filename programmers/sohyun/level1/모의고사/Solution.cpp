#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> p1 = {1, 2, 3, 4, 5};
    vector<int> p2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int cnt1 = 0, cnt2 = 0, cnt3 = 0; 
    for(int i = 0 ; i < answers.size(); i++){
        if(p1[i % p1.size()] == answers[i]){
            cnt1++;
        }
        if(p2[i % p2.size()] == answers[i]){
            cnt2++;
        }
        if(p3[i % p3.size()] == answers[i]){
            cnt3++;
        }
    }
    if(max({cnt1, cnt2, cnt3}) == cnt1) answer.push_back(1);
    if(max({cnt1, cnt2, cnt3}) == cnt2) answer.push_back(2);
    if(max({cnt1, cnt2, cnt3}) == cnt3) answer.push_back(3);
    
    return answer;
}