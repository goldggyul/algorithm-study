#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  set<string> nl;
  vector<string> answer;
  while(n--){
    string s;
    cin >> s;
    nl.insert(s);
  }
  while(m--){
    string s;
    cin >> s;
    if(nl.count(s)) answer.push_back(s);
  }
  
  sort(answer.begin(), answer.end());
  cout << answer.size() << endl;
  for(string a: answer) cout << a << endl;

  return 0;
}