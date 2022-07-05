#include <iostream>
#include <queue>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  queue<int> p;
  for(int i = 1; i <=n; i++)
    p.push(i);
  cout << "<";
  while(n--){
    for(int i = 1; i < k; i++){
      int f = p.front();
      p.pop();
      p.push(f);
    }
    cout << p.front();
    p.pop();
    if(!p.empty())  cout << ", ";
  }
  cout << ">\n";
  return 0;
}