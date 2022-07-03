#include <iostream>
#include <string>
using namespace std;

int palindrome(string s){
  int f = 0, l = s.size() - 1;
  bool isPseudo = false;
  while(f < l){
    if(s[f] != s[l]){
      if(s[f+1] != s[l] && s[f] != s[l-1])  return 2;
      if(s[f+1] == s[l]){
        isPseudo = true;
        int f2 = f+2; 
        int l2 = l-1;
        while(f2 < l2){
          if(s[f2] != s[l2]){
            isPseudo = false;
            break;
          }
          f2++;
          l2--;
        }
      }
      if(isPseudo)  return 1;
      if(s[f] == s[l-1]){
        isPseudo = true;
        int f2 = f+1;
        int l2 = l-2;
        while(f2 < l2){
          if(s[f2] != s[l2]){
            isPseudo = false;
            break;
          }
          f2++;
          l2--;
        }
      }
      if(isPseudo) return 1;
      else  return 2;
    }
    else{
      f++;
      l--;
    }
  }
  return 0;
}

int main(){
  int n;
  cin >> n;
  while(n--){
    string str;
    cin >> str;
    cout << palindrome(str) << endl;
  }
  return 0;
}