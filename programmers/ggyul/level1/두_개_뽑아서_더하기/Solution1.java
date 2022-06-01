import java.util.*;

class Solution {
    /*
     * https://programmers.co.kr/learn/courses/30/lessons/68644
     * N=100
     * 두 수 뽑아서 합이 총 뭐뭐가 있냐?
     * 
     * 최대 100+100=200
     */
    public int[] solution(int[] numbers) {
        int[] answer = {};

        boolean[] isSum = new boolean[200];

        for (int i = 0; i < numbers.length; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                isSum[numbers[i] + numbers[j]] = true;
            }
        }

        List<Integer> result = new ArrayList<Integer>();
        for (int i = 0; i < 200; i++) {
            if (isSum[i])
                result.add(i);
        }
        answer = result.stream().mapToInt(i -> i).toArray();
        return answer;
    }
}