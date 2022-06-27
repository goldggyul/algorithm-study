#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> v;
    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i : v) {
        answer *= 10;
        answer += i;
    }
    return answer;
}