package programmers.ggyul.level1.로또의_최고_순위와_최저_순위;

import java.util.*;

class Solution {
    public int getRank(int cnt) {
        switch (cnt) {
            case 6:
                return 1;
            case 5:
                return 2;
            case 4:
                return 3;
            case 3:
                return 4;
            case 2:
                return 5;
            default:
                return 6;
        }
    }

    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];

        int strikeCnt = 0;
        int zeroCnt = 0;

        for (int l : lottos) {
            if (l == 0) {
                zeroCnt++;
                continue;
            }
            for (int w : win_nums) {
                if (l == w) {
                    strikeCnt++;
                    break;
                }
            }
        }

        answer[1] = getRank(strikeCnt);
        int more = Math.min(zeroCnt, 6 - strikeCnt);
        answer[0] = getRank(strikeCnt + more);
        return answer;
    }
}