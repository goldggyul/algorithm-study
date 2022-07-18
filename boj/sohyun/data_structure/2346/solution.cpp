#include <iostream>
#include <deque>
using namespace std;

int main(){
  int n;
  cin >> n;
  deque<pair<int, int> > dq;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    dq.push_back(make_pair(i + 1, num));
  } 
  for(int i = 0; i < n; i++){
    int pos = dq.front().first;
    int nxt = dq.front().second;
    dq.pop_front();
    cout << pos << ' ';
    if(dq.empty())  break;
    if(nxt > 0){
      for(int j = 0; j < nxt - 1; j++){
        dq.push_back(dq.front());
        dq.pop_front();
      }
    }else{
      for(int j = 0; j < abs(nxt); j++){
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }
  }
  return 0;
}