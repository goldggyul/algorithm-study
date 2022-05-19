#include <string>
#include <vector>
#include <cctype>
using namespace std;

string toNum(string s)
{
  if (s == "zero")  return "0";
  if (s == "one") return "1";
  if (s == "two") return "2";
  if (s == "three") return "3";
  if (s == "four")  return "4";
  if (s == "five")  return "5";
  if (s == "six") return "6";
  if (s == "seven") return "7";
  if (s == "eight") return "8";
  if (s == "nine")  return "9";
  if (s == "")  return "";
}

bool isNum(string s)
{
  if (s == "zero" || s == "one" || s == "two" || s == "three" || s == "four" ||s == "five"|| s == "six" || s == "seven" || s == "eight" || s == "nine")
    return true;
  return false;
}

int solution(string s)
{
  int answer = 0;
  string result = "";
  string temp = "";
  for (int i = 0; i < s.size();){
    if (isdigit(s[i])){
      result += s[i];
      i++;
    }
    else{
      while (!isdigit(s[i])){
        temp += s[i];
        i++;
        if (isNum(temp)){
          result += toNum(temp);
          temp = "";
        }
      }
      result += toNum(temp);
      temp = "";
    }
  }
  answer = stoi(result);
  return answer;
}