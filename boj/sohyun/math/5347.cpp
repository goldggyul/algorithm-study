#include <iostream>
#include <vector>
using namespace std;

int getLcm(int a, int b){
  for(int i = 1; i <= b; i++){
    if((a*i) % b == 0)
      return a*i;
  }
}

int main(){
  int n;
  cin >> n; 
  vector<int> answer;
  while(n--){
    int a, b;
    cin >> a >> b;
    answer.push_back(getLcm(a,b));
  }
  for(int a: answer){
    cout << a << endl;
  }
  return 0;
}