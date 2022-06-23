#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  int answer = n;
  while(n--){
    string str;
    bool isIn[26] = {false};
    bool notGroup = false;
    cin >> str;
    str.erase(unique(str.begin(), str.end()), str.end());

    for(int i = 0; i < str.size(); i++){
      if(isIn[str[i]-97]) notGroup = true;
      else isIn[str[i]-97] = true;
    }
    if(notGroup)  answer--;
  }
  cout << answer << endl;
  return 0;
}