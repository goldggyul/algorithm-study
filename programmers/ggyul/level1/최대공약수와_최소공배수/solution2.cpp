#include <string>
#include <vector>
using namespace std;

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int gcd = GCD(n, m);
    answer.push_back(gcd);
    int lcm = gcd;
    answer.push_back(n * m / gcd);
    return answer;
}