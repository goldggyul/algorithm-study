import java.util.*;

class Solution {
    /*
    26분
    */
    public int[] solution(int N, int[] stages) {
        int[] answer = new int[N];
        for (int i = 0; i < N; i++) { // 1~N으로 채워놓기
            answer[i] = i + 1;
        }

        Map<Integer, Double> stageCnt = new HashMap<>();
        for (int s : stages) {
            stageCnt.put(s, stageCnt.getOrDefault(s, 0.0) + 1.0);
        }
        Double sum = stageCnt.getOrDefault(N + 1, 0.0);
        for (int i = N; i > 0; i--) {
            sum += stageCnt.getOrDefault(i, 0.0);
            // sum이 0일 때는 분자 역시 0이므로 divided by zero 걱정은 안해도 됨
            stageCnt.put(i, stageCnt.getOrDefault(i, 0.0) / sum);
        }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (stageCnt.getOrDefault(answer[i], 0.0) < stageCnt.getOrDefault(answer[j], 0.0)) {
                    answer[i] = answer[i] ^ answer[j];
                    answer[j] = answer[i] ^ answer[j];
                    answer[i] = answer[i] ^ answer[j];
                } else if (stageCnt.getOrDefault(answer[i], 0.0).equals(stageCnt.getOrDefault(answer[j], 0.0))) {
                    if (answer[i] > answer[j]) {
                        answer[i] = answer[i] ^ answer[j];
                        answer[j] = answer[i] ^ answer[j];
                        answer[i] = answer[i] ^ answer[j];
                    }
                }
            }
        }
        return answer;
    }
}