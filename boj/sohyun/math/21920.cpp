#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
  if(b == 0)  return a;
  return gcd(b, a%b);
}


int main(){
  int n, x;
  cin >> n;
  vector<int> a;
  while(n--){
    int num;
    cin >> num;
    a.push_back(num);
  }
  cin >> x;
  double sum = 0, cnt = 0;
  for(int i = 0; i < a.size(); i++){
    if(gcd(a[i], x) == 1){
      sum += a[i];
      cnt++;
    } 
  }
  cout << sum / cnt << endl;


  return 0;
}