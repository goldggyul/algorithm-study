// https://programmers.co.kr/learn/courses/30/lessons/12943
#include <string>
#include <vector>
using namespace std;

int solution(int num) {
    int answer = 0;
    while (num > 1) {
        if (answer >= 500)
            break;
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num *= 3;
            num++;
        }
        answer++;
    }
    if (answer > 500 || num != 1) {
        answer = -1;
    }
    return answer;
}