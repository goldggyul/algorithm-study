#include <iostream>
using namespace std;

bool isPrime[1'000'005];

int solution(int n) {
    int answer = 0;
    fill(isPrime + 2, isPrime + n + 1, true);
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        for (int j = i + i; j <= n; j += i) {
            isPrime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) answer++;
    }
    return answer;
}