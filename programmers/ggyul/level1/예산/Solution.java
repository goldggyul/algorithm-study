import java.util.*;

class Solution {
    /*
     * https://programmers.co.kr/learn/courses/30/lessons/12982?language=java
     * 최대한 많은 부서 지원해주기
     * 최대 10^7
     * 부서는 100개
     * 
     * 정답은 어떤 부서가 갖냐? 가 아니라 그냥 몇팀인지만 물어본다.
     * 따라서 그냥 정렬해서 작은 것부터 계산해도 상관이 없다.
     * (6분)
     */
    public int solution(int[] d, int budget) {
        int answer = 0;

        Arrays.sort(d);

        for (int i : d) {
            budget -= i;
            if (budget < 0) {
                return answer;
            }
            answer++;
        }
        return answer;
    }
}