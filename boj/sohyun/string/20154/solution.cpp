#include <iostream>
#include <string>

using namespace std;


int getNum(char a){
  if(a == 'C' || a == 'I' || a == 'J' || a == 'L' || a == 'O' || a == 'S' || a == 'U' || a == 'V' || a == 'Z')
    return 1;
  if(a == 'B' || a == 'D' || a == 'P' || a =='Q' || a == 'R' || a == 'T' || a == 'W' || a == 'X' || a == 'Y')
    return 2;
  if(a == 'A' || a == 'E' || a == 'F' || a =='G' || a == 'H' || a == 'K' || a == 'M' || a == 'N')
    return 3;
}

int main(){
  string s;
  cin >> s;
  int sum = 0;
  for(int i = 0; i < s.size(); i+=2){
    if(i != s.size() -1){
      sum += getNum(s[i]) + getNum(s[i+1]);
    }
    else{
      sum += getNum(s[i]);
    }
    if(sum > 10) sum %= 10;
  }
  if(sum % 2 == 0)  cout << "You're the winner?" << endl;
  else  cout << "I'm a winner!" << endl;
  return 0;
}