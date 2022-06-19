#include <iostream>
#include <string>
using namespace std;

int main(){
  int cnt;
  string n;
  int sum = 0;
  cin >> cnt >> n;
  for(int i = 0; i < cnt;i++){
    sum += n[i] - '0';
  }
  cout << sum << endl;
  return 0;
}