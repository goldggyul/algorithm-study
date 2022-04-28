// https://www.acmicpc.net/problem/5347
// https://ko.wikipedia.org/wiki/��Ŭ����ȣ����

#include <iostream>
using namespace std;

int n, a, b;

long long gcd(int a, int b) {
    // (a,b)=(b,r)
    return (b > 0) ? gcd(b, a % b) : a;
}

long long lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << lcm(a, b) << endl;
    }
    return 0;
}