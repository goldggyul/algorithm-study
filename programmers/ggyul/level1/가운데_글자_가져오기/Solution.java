// https://programmers.co.kr/learn/courses/30/lessons/12903
class Solution {
    public String solution(String s) {
        String answer = "";
        answer = Character.toString(s.charAt(s.length() / 2));
        if (s.length() % 2 == 0) { // 짝수
            answer = Character.toString(s.charAt(s.length() / 2 - 1)) + answer;
        }
        return answer;
    }
}