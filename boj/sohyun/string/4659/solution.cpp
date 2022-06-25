#include <iostream>
#include <string>
#include <vector> 
using namespace std;

bool isVowel(char c){
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){
  vector<bool> isAccept;
  vector<string> password;
  while(true){
    string pw;
    cin >> pw;
    password.push_back(pw);
    if(pw == "end") break;
    bool vowelIn = false;
    bool notContinue3 = true;
    bool notContinue2 = true;
 
    for(int i = 0; i < pw.size(); i++){ 
      if(isVowel(pw[i])){
        vowelIn = true;
        if(i+2 < pw.size()){
          if(isVowel(pw[i+1]) && isVowel(pw[i+2]))  notContinue3 = false;
        }  
      }else{
        if(i+2 < pw.size()){
          if(!isVowel(pw[i+1]) && !isVowel(pw[i+2]))  notContinue3 = false;
        }  
      }
      if(i+1 < pw.size()){
        if(pw[i] == pw[i+1]){
          if(pw[i] != 'e' && pw[i] != 'o')  notContinue2 = false;
        }
      }
    }
    if(vowelIn && notContinue2 && notContinue3) isAccept.push_back(true);
    else  isAccept.push_back(false);

  }

  for(int i = 0; i < isAccept.size(); i++){
    if(isAccept[i]) cout << "<" << password[i] << "> is acceptable." << endl;
    else  cout << "<" << password[i] << "> is not acceptable." << endl;
  }


  return 0;
}