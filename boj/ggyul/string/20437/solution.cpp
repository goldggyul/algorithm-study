// https://www.acmicpc.net/problem/20437
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string w;
        cin >> w;
        int k;
        cin >> k;

        vector<int> ans;

        int shortest = -1;
        int longest = -1;
        for (char c = 'a'; c <= 'z'; c++) {
            vector<int> finded;
            for (int i = 0; i < w.size(); i++) {
                if (w[i] == c) finded.push_back(i);
            }
            for (int i = k - 1; i < finded.size(); i++) {
                int differ = finded[i] - finded[i - k + 1] + 1;
                if (shortest == -1 || differ < shortest) shortest = differ;
                if (longest == -1 || differ > longest) longest = differ;
            }
        }

        if (shortest == -1) {
            cout << shortest << endl;
        } else {
            cout << shortest << " " << longest << endl;
        }
    }
    return 0;
}