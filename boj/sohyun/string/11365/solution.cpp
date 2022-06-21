#include <iostream>
#include <string>
using namespace std;

int main(){
  string code = "";
  string answer = "";
  while(true){
    getline(cin, code);
    if(code == "END") break;
    for(auto it = code.end()-1; it != code.begin()-1; it--){
      answer += *it;
    }
    answer += "\n";
  }
  cout << answer << endl;
  return 0;
}