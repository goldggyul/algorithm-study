#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string s1, string s2){
  if(s1.size() == s2.size()){
    return s1 < s2;
  }
  return s1.size() < s2.size();
}

int main(){
  int n;
  cin >> n;
  vector<string> answer;
  while(n--){
    string str;
    cin >> str;
    answer.push_back(str);
  }
  sort(answer.begin(), answer.end(), comp);
  answer.erase(unique(answer.begin(), answer.end()), answer.end());
  for(string s: answer)
    cout << s << endl;
  
  return 0;
}