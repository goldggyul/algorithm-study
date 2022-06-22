#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<char, int> p1, pair<char, int> p2){
      return p1.second > p2.second;
}

int main(){
  int n; 
  vector<char> answer;
  cin >> n;
  cin.ignore();
  while(n--){
    string s = "";
    getline(cin,s);
    map<char, bool> check;
    map<char, int> cnt;
    for(int i = 0; i < s.size(); i++){
      if(!check[s[i]] && s[i] != ' '){
        check[s[i]] = true;
        cnt[s[i]] = count(s.begin() + i, s.end(), s[i]);
      }
    }
    vector<pair<char,int> > v(cnt.begin(), cnt.end());
    sort(v.begin(), v.end(), comp);
    int max = v[0].second;
    bool isMax = true;
    for(int i = 1; i < v.size(); i++){
      if(max == v[i].second)  isMax = false;
    }
    if(!isMax) answer.push_back('?');
    else  answer.push_back(v[0].first);
  }
  for(char c : answer){
    cout << c << endl;
  }
  return 0;
}