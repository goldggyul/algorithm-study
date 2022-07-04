#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  queue<int> q;
  while(n--){
    string cmd;
    cin >> cmd;
    if(cmd == "push"){
      int n;
      cin >> n;
      q.push(n);
    }
    else if(cmd == "pop"){
      if(q.empty()) cout << -1 << '\n';
      else{
        cout << q.front() << '\n';
        q.pop();
      }
    }
    else if(cmd == "size") cout << q.size() << '\n';
    else if(cmd == "empty"){
      if(q.empty()) cout << 1 << '\n';
      else  cout << 0 << '\n';
    }
    else if(cmd == "front"){
      if(q.empty()) cout << -1 << '\n';
      else  cout << q.front() << '\n';
    }
    else if(cmd == "back"){
      if(q.empty()) cout << -1 << '\n';
      else  cout << q.back() << '\n';
    }
  }

  return 0;
}