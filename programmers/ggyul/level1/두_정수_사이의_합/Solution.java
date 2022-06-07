// https://programmers.co.kr/learn/courses/30/lessons/12912
class Solution {
    public long solution(int a, int b) {
        long answer = 0;
        if (a == b)
            return a;
        if (a > b) {
            a = a ^ b;
            b = a ^ b;
            a = a ^ b;
        }
        for (int i = a; i <= b; i++)
            answer += i;
        return answer;
    }
}