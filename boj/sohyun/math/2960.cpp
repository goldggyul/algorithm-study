#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool isPrime(int n){
  for(int i = 2; i < n; i++){
    if(n % i == 0)  return false;
  }
  return true;
}

int main(){
  int n, k; 
  cin >> n >> k;
  vector<int> v;
  map<int,bool> flag;

  for(int i = 2; i <= n; i++){
    flag[i]=false;
  }
  for(int i = 2; i <= n; i++){
    if(isPrime(i)){
      for(int j = 1; i*j <= n; j++){
        if(!flag[i*j]){
          flag[i*j]= true;
          v.push_back(i*j);
        }
      }
    }
  }
  cout << v[k-1] << endl;
}


