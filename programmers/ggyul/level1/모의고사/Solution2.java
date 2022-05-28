import java.util.*;

// 15분
class Solution {

    public int[] solution(int[] answers) {
        int[] answer = {};
        int[][] pattern = new int[][] {
                { 1, 2, 3, 4, 5 },
                { 2, 1, 2, 3, 2, 4, 2, 5 },
                { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, }
        };

        int[] scores = new int[pattern.length];
        for (int i = 0; i < answers.length; i++) {
            for (int j = 0; j < pattern.length; j++) {
                if (answers[i] == pattern[j][i % pattern[j].length])
                    scores[j]++;
            }
        }

        int max = 0;
        for (int i = 0; i < scores.length; i++) {
            if (max < scores[i])
                max = scores[i];
        }

        List<Integer> winners = new ArrayList<>();
        for (int i = 0; i < scores.length; i++) {
            if (max == scores[i])
                winners.add(i + 1);
        }
        Collections.sort(winners);

        answer = winners.stream()
                .mapToInt(i -> i)
                .toArray();

        return answer;
    }
}