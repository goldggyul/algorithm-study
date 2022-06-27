#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(long long n) {
    long long answer = -1;
    for (long long i = 1; i <= sqrt(n); i++) {
        if (i * i == n) {
            answer = (i + 1) * (i + 1);
            break;
        }
    }
    return answer;
}