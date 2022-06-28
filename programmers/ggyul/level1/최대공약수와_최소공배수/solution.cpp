#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int a = (n > m) ? m : n;
    int b = (n > m) ? n : m;
    int gcd = 1;
    for (int i = a; i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
            break;
        }
    }
    answer.push_back(gcd);
    int lcm = gcd;
    lcm *= (a / gcd);
    lcm *= (b / gcd);
    answer.push_back(lcm);
    return answer;
}