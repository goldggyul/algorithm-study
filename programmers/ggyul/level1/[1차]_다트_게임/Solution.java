// https://programmers.co.kr/learn/courses/30/lessons/17682
class Solution {
    /*
     * 총 3번
     * 0~10점
     * S, D, T -> 1승 2승 3승
     * -> 해당 점수 + 바로 전 점수 2배, # -> 마이너스
     */
    public int solution(String dartResult) {
        int answer = 0;
        int[] scores = new int[3];
        int index = 0;
        for (int i = 0; i < 3; i++) {
            int score = dartResult.charAt(index++) - '0';
            if (dartResult.charAt(index) == '0') {
                score = 10;
                index++;
            }
            char powNum = dartResult.charAt(index++);
            if (powNum == 'D')
                score = score * score;
            else if (powNum == 'T')
                score = score * score * score;
            if (index < dartResult.length()) {
                if (dartResult.charAt(index) == '*') {
                    score *= 2;
                    if (i > 0) {
                        scores[i - 1] *= 2;
                    }
                    index++;
                } else if (dartResult.charAt(index) == '#') {
                    score *= (-1);
                    index++;
                }
            }
            scores[i] = score;
        }
        for (int i = 0; i < 3; i++) {
            answer += scores[i];
        }
        return answer;
    }
}