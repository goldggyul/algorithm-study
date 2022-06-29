#include <string>
#include <vector>
using namespace std;

// a, b의 최대공약수와, b, a%b의 최대공약수는 같다.
// (a,b)->(b,a%b)->...(gcd, 0)
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