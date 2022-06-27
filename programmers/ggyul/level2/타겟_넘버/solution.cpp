// https://programmers.co.kr/learn/courses/30/lessons/43165
#include <string>
#include <vector>
using namespace std;

int answer = 0;
int target;
vector<int> numbers;
vector<bool> isNegative;

void dfs(int i) {
    if (i == numbers.size()) {
        int ans = 0;
        for (int i = 0; i < isNegative.size(); i++) {
            if (isNegative[i]) {
                ans += -numbers[i];
            } else {
                ans += numbers[i];
            }
        }
        if (ans == target) answer++;
        return;
    }
    // 1. i가 양수
    dfs(i + 1);
    // 2. i가 음수
    isNegative[i] = true;
    dfs(i + 1);
    isNegative[i] = false;
}

int solution(vector<int> _numbers, int _target) {
    numbers = _numbers;
    target = _target;
    isNegative.resize(numbers.size());
    dfs(0);
    return answer;
}