#include <iostream>
#include <vector>
using namespace std;

int getLcm(int a, int b){
  for (int i = 1; i <= b; i++){
    if ((a * i) % b == 0)
      return a * i;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> answer;
  while (n--){
    int a, b;
    cin >> a >> b;
    answer.push_back(getLcm(a, b));
  }
  for (int i : answer)
    cout << i << endl;

  return 0;
}