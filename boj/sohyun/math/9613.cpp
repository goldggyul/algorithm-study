#include <iostream>
#include <vector>
using namespace std;


int gcd(int a, int b){
  if(b == 0)  return a;
  return gcd(b, a%b);
}

int main(){
  int n;
  cin >> n;
  while(n--){
    int t;
    vector<int> num;
    cin >> t;
    while(t--){
      int tn;
      cin >> tn;
      num.push_back(tn);
    }
    long long sum = 0;
    for(int i = 0; i < num.size() - 1; i++){
      for(int j = i + 1; j < num.size(); j++){
        sum += gcd(num[i], num[j]);
      }
    }
    cout << sum << endl;
  }

  return 0;
}