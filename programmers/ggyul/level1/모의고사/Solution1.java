import java.util.*;

// 25분
class Solution {
    class MathGiveUper {
        int[] answer;
        int target = 0;
        int score = 0;

        MathGiveUper(int[] answer) {
            this.answer = answer;
        }

        public int getAnswer() {
            if (target == answer.length) {
                target = 0;
            }
            return answer[target++];
        }

        public void addScore() {
            score++;
            if (max < score)
                max = score;
        }

        public int getScore() {
            return score;
        }
    }

    int max = 0;

    public int[] solution(int[] answers) {
        int[] answer = {};
        MathGiveUper[] supoja = new MathGiveUper[] {
                new MathGiveUper(new int[] { 1, 2, 3, 4, 5 }),
                new MathGiveUper(new int[] { 2, 1, 2, 3, 2, 4, 2, 5 }),
                new MathGiveUper(new int[] { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, })
        };

        for (int a : answers) {
            for (MathGiveUper s : supoja) {
                if (s.getAnswer() == a) {
                    s.addScore();
                }
            }
        }

        List<Integer> winners = new ArrayList<Integer>();
        for (int i = 0; i < supoja.length; i++) {
            if (supoja[i].getScore() == max) {
                winners.add(i + 1);
            }
        }
        Collections.sort(winners);

        answer = winners.stream()
                .mapToInt(i -> i)
                .toArray();
        return answer;
    }
}