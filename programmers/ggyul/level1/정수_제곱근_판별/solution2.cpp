#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(long long n) {
    long long answer = -1;
    if (sqrt(n) == floor(sqrt(n)))
        answer = (sqrt(n) + 1) * (sqrt(n) + 1);
    return answer;
}