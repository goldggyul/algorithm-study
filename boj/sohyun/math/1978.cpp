#include <iostream>

using namespace std;

int main(){
  int n; 
  cin >> n; 
  int primeCount = 0; 
  while(n--){
    int a; 
    cin >> a;
    if(a == 1)  continue;

    bool isPrime = true;
    for(int i = 2; i < a; i++){
      if(a % i == 0){
        isPrime = false;
        break;
      }
    }
    if(isPrime) primeCount++;
  }
  cout << primeCount << endl;
  return 0;
}