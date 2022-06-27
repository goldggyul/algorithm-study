#include <iostream>
#include <string>
using namespace std;

int main(){
  string str;
  getline(cin,str);
  string word, answer;
  for(int i = 0; i < str.size(); i++){
    if(str[i] == '<'){
      if(!word.empty()){
        for(int j = word.size()-1; j >= 0; j--){
          answer += word[j];
        }
        word = "";
      }
      while(str[i] != '>'){
        answer += str[i];
        i++;
      }
      answer += '>';
      continue;
    }
    word += str[i];
    if(str[i] == ' '){
      word.pop_back();
      for(int j = word.size()-1; j >= 0; j--){
        answer += word[j];
      }
      answer += ' ';
      word = "";
      continue;
    }
    if(i == str.size()-1){
      for(int j = word.size()-1; j >= 0; j--){
        answer += word[j];
      }
      break;
    }
   
  }
  cout << answer << endl;
  return 0;
}