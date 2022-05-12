#include <iostream>
using namespace std;

int fatigue, workAmount, rest, maxFatigue;

int main() {
    cin >> fatigue >> workAmount >> rest >> maxFatigue;
    int t = 24;
    int result = 0;
    int fatigueSum = 0;
    while (t) {
        if (fatigueSum+fatigue<=maxFatigue) {
            result += workAmount;
            fatigueSum += fatigue;
        } else {
            fatigueSum -= rest;
            if (fatigueSum < 0) {
                fatigueSum = 0;
            }
        }
        t--;
    }
    cout << result << endl;
    return 0;
}