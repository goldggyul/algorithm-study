#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main(){
  string t1 = "", t2 = "";
  cin >> t1 >> t2;
  vector<int> currentTime;
  vector<int> throwTime;
  stringstream ss1(t1);
  string tmp; 
  while(getline(ss1, tmp, ':')){
    currentTime.push_back(stoi(tmp));
  }
  stringstream ss2(t2);
  while(getline(ss2, tmp, ':')){
    throwTime.push_back(stoi(tmp));
  }

  vector<int> answer(3);
  for(int i = 2; i >= 0; i--){
    if(i == 0){
      if(throwTime[i]- currentTime[i] < 0){
        answer[i] = 24 + throwTime[i] - currentTime[i];
        continue;
       }
    }else{
      if(throwTime[i]- currentTime[i] < 0){
            throwTime[i-1]--;
            answer[i] = 60 + throwTime[i] - currentTime[i];
            continue;
      }
    }
    answer[i] = throwTime[i] - currentTime[i];
  }
  if(answer[0] == 0 && answer[1] == 0 && answer[2] == 0){
    cout << "24:00:00" <<endl;
    return 0;
  }

  for(int i = 0; i < answer.size(); i++){
    string temp = "";
    if(answer[i] < 10){
      temp += "0" + to_string(answer[i]);
    }
    else temp = to_string(answer[i]);
    if(i != answer.size()-1)  cout << temp + ":";
    else cout << temp;
  }
  return 0;
}