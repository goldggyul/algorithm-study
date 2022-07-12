#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  stack<int> st;
  stack<int> tmp;
  vector<int> sequence;
  vector<string> answer;
  bool isPossible = true;
  for(int i = n; i >= 1; i--){
    tmp.push(i);
  }
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    sequence.push_back(num);
  }
  for(int i = 0; i < sequence.size(); i++){
    if(st.empty() || st.top() < sequence[i]){
      while(true){
        st.push(tmp.top());
        tmp.pop();
        answer.push_back("+");
        if(st.top() == sequence[i]) break;
      }
    }
    if(st.top() == sequence[i]){
      st.pop();
      answer.push_back("-");
    } 
    else if(st.top() > sequence[i]){
      isPossible = false;
      break;
    } 
  }
  if(!isPossible) cout << "NO\n";
  else{
    for(string s: answer) cout << s << "\n";
  }
  return 0;
}