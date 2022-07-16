#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main(){
  int n;
  cin >> n;
  while(n--){
    int docsNum, pos; // 문서 개수, 궁금한 문서의 위치
    cin >> docsNum >> pos;

    queue<pair<int, int> > q;
    priority_queue<int> pq;
    int answer = 0;

    for(int i = 0; i < docsNum; i++){
      int importance;
      cin >> importance;
      q.push(make_pair(i, importance));
      pq.push(importance);
    }
    while(!q.empty()){
      int p = q.front().first;
      int doc = q.front().second;
      if(doc!= pq.top()){
        q.pop();
        q.push(make_pair(p, doc));
      }else{
        answer++;
        q.pop();
        pq.pop();
        if(pos == p){
          cout << answer << '\n';
          break;
        }
      }
    }
  }
  return 0;
}