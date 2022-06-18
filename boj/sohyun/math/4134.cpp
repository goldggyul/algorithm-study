#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long getPrime(long long n){
  bool isPrime = false;
  if(n == 0 || n == 1)  return 2;
  while(!isPrime){
    isPrime = true;
    for(int i = 2; i <= sqrt(n); i++){
      if(n % i == 0){
        isPrime = false;
        break;
      }
    }
    if(!isPrime)  n++;
  }
  return n;
}

int main(){
  long long n;
  cin >> n;
  vector<long long> answer;
  while(n--){
    long long a;
    cin >> a;
    answer.push_back(getPrime(a));
  }
  for(long long a: answer)
    cout << a << endl;
  return 0;
}