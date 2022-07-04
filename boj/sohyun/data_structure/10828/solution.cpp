#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();
  vector<int> stack;
  while(n--){
    string c;
    getline(cin, c);
    stringstream ss(c);
    string s;
    while(ss >> s){
      if(s == "push"){
        int num;
        ss >> num;
        stack.push_back(num);
      }
      else if(s == "pop"){
        if(stack.empty())
          cout << -1  << endl;
        else{
          cout << stack.back() << endl;
          stack.pop_back();
        }
      }
      else if(s == "size")  cout << stack.size() << endl;
      else if(s == "empty"){
        if(stack.empty()) cout << 1 << endl;
        else cout << 0 << endl;
      }
      else if(s == "top"){
        if(stack.empty()) cout << -1 << endl;
        else  cout << stack.back() << endl;
      }
    }
  }
  return 0;
}