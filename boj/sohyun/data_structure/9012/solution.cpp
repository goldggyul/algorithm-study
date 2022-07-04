#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  while(n--){
    string ps;
    cin >> ps;
    vector<int> p;
    bool isVPS = true;
    for(int i = 0; i < ps.size(); i++){
      if(ps[i] == '(')  p.push_back(1);
      else if(ps[i] == ')'){
        if(p.empty()) isVPS = false;
        else  p.pop_back();
      }
    }
    if(isVPS && p.empty()) cout << "YES" << endl;
    else  cout << "NO" << endl;
  }
  return 0;
}