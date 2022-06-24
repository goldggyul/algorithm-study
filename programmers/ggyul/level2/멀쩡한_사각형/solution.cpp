// https://programmers.co.kr/learn/courses/30/lessons/62048
#include <iostream>
#include <cmath>
using namespace std;

long long solution(int _w, int _h) {
    long long w = _w;
    long long h = _h;
    long long answer = w * h;

    for (int i = 0; i < w; i++) {
        long long leftY = -h * i + w * h;
        long long rightY = -h * (i + 1) + w * h;
        if (leftY % w != 0) { // 올림
            leftY = leftY / w + 1;
        } else {
            leftY = leftY / w;
        }
        rightY = rightY / w; //버림
        answer -= (leftY - rightY);
    }

    return answer;
}