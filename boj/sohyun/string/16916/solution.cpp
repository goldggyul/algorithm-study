#include <iostream>
#include <string>
#include <vector>
using namespace std;

// KMP 알고리즘
vector<int> getFailureFunction(string pattern){
  vector<int> failure(pattern.size(), 0);
  int j = 0;
  for(int i = 1; i < pattern.size(); i++){
    while(j > 0 && pattern[i] != pattern[j]){
      j = failure[j-1];
    }
    if(pattern[i] == pattern[j]){
      failure[i] = ++j;
    }
  }
  return failure;
}

void kmp(string str, string pattern){
  vector<int> failureFunction = getFailureFunction(pattern);
  int j = 0;
  bool isSubstr = false;
  for(int i = 0; i < str.size(); i++){
    while(j > 0 && str[i] != pattern[j]){
      j = failureFunction[j-1];
    }
    if(str[i] == pattern[j]){
      if(j == pattern.size() - 1){
        isSubstr = true;
        j = failureFunction[j];
      }
      else  j++;
    }
  }
  if(isSubstr)  cout << "1" << endl;
  else  cout << "0" << endl;
}


int main(){
  string s, p;
  cin >> s >> p;
  kmp(s, p);

  return 0;
}