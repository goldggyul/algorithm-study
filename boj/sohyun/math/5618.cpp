#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
  int count;
  cin >> count;
  vector<int> num;
  set<int> result;
  vector<int> tmp;

  for (int i = 0; i < count; i++){
    int n;
    cin >> n;
    num.push_back(n);
  }
  for (int i = 0; i < num.size(); i++){
    for (int j = 1; j < num[i]+1; j++){
      if(num[i] % j == 0){
        result.insert(j);
      }
    }
  }
  for (int i = 0; i < num.size(); i++){
    for (auto it = result.begin(); it != result.end(); ){
      if(num[i] % *it != 0){
        result.erase(it++);
      }
      else{
        ++it;
      }
    }
  }
  for (auto it = result.begin(); it != result.end(); ++it)
    cout << *it <<endl;
  
  return 0;
}