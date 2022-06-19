#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int solution(int n)
{
    int answer = 0;
    int d = pow(10, to_string(n).size());
    
    while(d/=10){
        answer += n / d;
        n %= d;
    }

    return answer;
}