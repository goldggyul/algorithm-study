import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = {};

        Set<Integer> sum = new TreeSet<>();

        for (int i = 0; i < numbers.length; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                sum.add(numbers[i] + numbers[j]);
            }
        }

        answer = sum.stream().mapToInt(i -> i).toArray();
        return answer;
    }
}