// https://www.acmicpc.net/problem/5347

#include <iostream>
using namespace std;

int n, a, b;

int main() {
    cin >> n;
    while (n--) {
        cin >> a >> b;
        if (b < a) {
            int temp = b;
            b = a;
            a = temp;
        }
        long long mul = 1;

        int i;
        for (i = a; i >= 1; i--) {
            if ((a % i == 0) && (b % i == 0)) {
                mul *= i;
                a /= i;
                b /= i;
                if (i == 1) break;
                i = a + 1;
            }
        }
        mul *= a;
        mul *= b;
        cout << mul << endl;
    }

    return 0;
}