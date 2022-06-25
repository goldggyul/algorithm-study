#include <iostream>
#include <string>
using namespace std;

int main(){
  string s, k;
  cin >> s >> k;
  int answer = 0;
  for(auto it = s.begin(); it != s.end();){
    if(isdigit(*it)){
      s.erase(it);
      it--;
    }
    else it++;
  }
  for(int i = 0; i < s.size(); i++){
    for(int j = 1 ; (i+j) <= s.size(); j++){
      if(s.substr(i,j) == k)  answer = 1;  
    }
  }
  cout << answer << endl;
  return 0;
}