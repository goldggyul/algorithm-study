#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s, p;
vector<int> table;
void makeTable() { // 패턴 p에 대한 테이블
    table.resize(p.size(), 0);
    int comp = 0;
    for (int i = 1; i < p.size(); i++) {
        while (comp > 0 && p[i] != p[comp]) {
            comp = table[comp - 1];
        }
        if (p[i] == p[comp]) {
            table[i] = comp + 1;
            comp++;
        }
    }
}

bool kmp() {
    int comp = 0;
    for (int i = 0; i < s.size(); i++) {
        while (comp > 0 && s[i] != p[comp]) {
            comp = table[comp - 1];
        }
        if (s[i] == p[comp]) {
            if (comp == p.size() - 1) {
                return true;
                //comp = table[comp];
            } else {
                comp++;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> p;
    makeTable();
    cout << kmp() << endl;

    return 0;
}