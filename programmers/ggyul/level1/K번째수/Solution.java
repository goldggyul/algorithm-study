import java.util.*;

class Solution {
    /*
     * https://programmers.co.kr/learn/courses/30/lessons/42748?language=java
     * 0 base index
     * [i,j]
     * array -> 100, command -> 50
     * 50 * 100log100
     * (15분)
     */
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for (int i = 0; i < commands.length; i++) {
            int[] command = commands[i];
            int from = command[0] - 1, to = command[1] - 1, target = command[2] - 1;

            int[] temp = new int[to - from + 1];
            for (int j = 0; j < to - from + 1; j++) {
                temp[j] = array[j + from];
            }
            Arrays.sort(temp);
            answer[i] = temp[target];
        }
        return answer;
    }
}