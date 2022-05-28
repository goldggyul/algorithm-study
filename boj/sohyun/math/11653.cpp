#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n; 
  cin >> n;
  if(n == 1)  return 0;
  for(int i = 2; i <= n; i++){
    while(n % i == 0){
      n /= i; 
      cout<< i << endl;
    }
  }
  return 0;
}