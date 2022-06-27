#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(){
  int n;
  cin >> n;
  regex re("[A-F]?A+F+C+[A-F]?");
  while(n--){
    string chromosome;
    cin >> chromosome;
    if(regex_match(chromosome, re)) cout << "Infected!" << endl;
    else  cout <<  "Good" << endl;
  }
  
  return 0;
}