#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main(){
  int n;
  cin >> n;
  vector<int> a;
  set<int> prime;
  while(n--){
    int num;
    cin >> num;
    a.push_back(num);
  }
  bool isPrime = true;
  for(int i = 0; i < a.size(); i++){
    isPrime = true;
    for(int j = 2; j*j <= a[i]; j++){
      if(a[i] % j == 0){
        isPrime = false;
        break;
      }
    }
    if(isPrime) prime.insert(a[i]);
  }
  if(prime.empty()) cout << -1 << endl;
  else{
    long long answer = 1;
    for(int p: prime){
      answer *= p; 
    }
    cout << answer << endl;
  }
  return 0;
}