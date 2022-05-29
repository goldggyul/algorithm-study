#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(pair<int, double>& a, pair<int, double>& b){
    if(a.second > b.second){
        return true;
    }else if(!(a.second < b.second)){
        if(a.first < b.first){
            return true;
        }
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int ,int> player; 
    map<int, double> fail;

    for(int i = 0; i < N; i++){
        player[i+1] = 0; 
    }
    for(int i = 0; i < stages.size(); i++){
        if(stages[i] != N+1)    player[stages[i]]++;
    }

    int playerNum = stages.size();
    for(auto it = player.begin(); it!= player.end(); ++it){
        double failureRate = (double)(it->second) / playerNum;
        fail[it->first] = failureRate;
        playerNum -= it->second; 
    }

    vector<pair<int,double>> v(fail.begin(),fail.end());
    sort(v.begin(), v.end(), cmp);
    for(auto it: v){
        answer.push_back(it.first);
    }

    return answer;
}