#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pNum = 0, yNum = 0;
    for(char c: s){
        if(c == 'p' || c == 'P')    pNum++;
        if(c == 'y' || c == 'Y')    yNum++;
    }
    if(pNum != yNum)    answer = false;

    return answer;
}