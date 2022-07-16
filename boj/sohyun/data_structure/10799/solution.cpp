#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
  string p;
  cin >> p;
  int laser = 0; 
  int total = 0;
  stack<char> st;
  for(int i = 0; i < p.size(); i++){
    if(p[i] == '('){
      st.push(p[i]);
    }else{
      st.pop();
      if(p[i-1] == '(') // 레이저
        total += st.size();
      else
        total++;
    }
  }
  cout << total << '\n';
  return 0;
}