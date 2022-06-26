#include <iostream>
#include <string>

using namespace std;

int main(){
  string s, t;
  while(cin >> s >> t){
    string str = "";
    int idx = 0;
    for(int i = 0; i < s.size(); i++){
      for(int j = idx; j < t.size(); j++){
        if(s[i] == t[j]){
          str += s[i];
          idx = j + 1;
          break;
        }
      }
    }
    if(str == s)  cout << "Yes" << endl;
    else  cout << "No" << endl;
  }
  return 0;
}