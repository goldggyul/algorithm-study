#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  int n = 5;
  vector<string> str;
  string answer = "";
  while(n--){
    string s;
    cin >> s;
    str.push_back(s);
  }
  int max_length = 0;
  for(int i = 0; i < str.size(); i++){
    if(max_length < str[i].size()) max_length = str[i].size();
  }
  for(int i = 0; i < max_length; i++){
    for(int j = 0; j < str.size(); j++){
      if(str[j].size() < i + 1) continue;
      answer += str[j][i];
    }
  }
  cout << answer << endl;

  return 0;
}