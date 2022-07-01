#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int a){
  string n = to_string(a);
  int f = 0, l = n.size() - 1;
  while(f < l){
    if(n[f] != n[l])  return false;
    f++;
    l--;
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  if(n == 1){
    cout << 2 << endl;
    return 0;
  }
  while(true){
    bool isPrime = true;
    for(int i = 2; i*i <= n; i++){
      if(n % i == 0 || !isPalindrome(n)){
        isPrime = false;
        break;
      }
    }
    if(isPrime && isPalindrome(n)){
      cout << n << endl;
      return 0;
    }
    n++;
  }

  return 0;
}