#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
  int n;
  cin >> n;
  map<string, int> cnt;
  while(n--){
    string file;
    cin >> file;
    int dotIndex = file.find('.');
    string extension = file.substr(dotIndex + 1, file.size() - dotIndex);
    cnt[extension]++;
  }
  for(auto it = cnt.begin(); it != cnt.end(); it++){
    cout << it->first << " " <<it->second << endl;
  }

  return 0;
}