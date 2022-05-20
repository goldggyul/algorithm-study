#include <iostream>
#include <vector>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  vector<int> v1;
  vector<int> v2; 
  for(int i = 1; i <= a; i++){
    if(a % i == 0)
      v1.push_back(i);
  }
  for(int i = 1; i <= b; i++){
    if(b % i == 0)
      v2.push_back(i);
  }
  vector<int> same;
  for(int i = 0 ; i < v1.size(); i++){
    for(int j = 0; j < v2.size(); j++ ){
      if(v1[i] == v2[j]){
        same.push_back(v1[i]);
      }
    }
  }
  int n1 = a / same.back();
  int n2 = b / same.back();
  cout << same.back() <<endl;
  cout << same.back() * n1 * n2 << endl;
  return 0;
}