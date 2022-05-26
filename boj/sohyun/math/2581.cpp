#include <iostream>
#include <vector>
using namespace std;

int main(){
  int m,n;
  vector<int> prime;
  int sum = 0; 
  cin >> m >> n;
  
  for(int i = m; i <= n; i++){
    bool isPrime = true;
    for(int j = 2; j < i; j++){
      if(i%j == 0){
        isPrime = false;
        break;
      }
    }
    if(isPrime && i != 1 || i == 2){
        prime.push_back(i);
    }
  }
  if(prime.empty()) cout << "-1" << endl;
  else{
    for(int i = 0; i < prime.size(); i++){
      sum += prime[i];
    }
    cout << sum << endl;
    cout << prime.front() << endl;
  }


  return 0;
}