// https://programmers.co.kr/learn/courses/30/lessons/64061
import java.util.*;

class Solution {
    // 해당 move 열에 가장 위의 X좌표 리턴
    public int getTopPos(int[][] board, int move) {
        int result = -1;
        for (int i = 0; i < board[0].length; i++) {
            if (board[i][move] != 0) {
                return i;
            }
        }
        return result;
    }

    public int solution(int[][] board, int[] moves) {
        int answer = 0;

        Stack<Integer> s = new Stack<>();
        for (int move : moves) {
            // index 0-base로 변경
            move--;
            int topPos = getTopPos(board, move);
            if (topPos == -1) { // 인형이 없는 열인 경우
                continue;
            } else {
                // 바구니에 같은 인형이 있을 경우
                if (!s.empty() && s.peek() == board[topPos][move]) {
                    while (!s.empty() && s.peek() == board[topPos][move]) {
                        s.pop();
                        answer++;
                    }
                    answer++; // 현재 move까지 answer에 반영
                } else {
                    s.push(board[topPos][move]);
                }
                board[topPos][move] = 0;
            }
        }
        return answer;
    }
}