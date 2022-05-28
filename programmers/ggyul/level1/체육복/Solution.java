import java.util.*;

class Solution {
    /*
     * reverse에 있어도 lost에 있다면 빌려줄 수 없다
     */
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;

        int clothCnt[] = new int[n + 1];
        Arrays.fill(clothCnt, 1);
        for (int r : reserve) {
            clothCnt[r] = 2;
        }
        for (int l : lost) {
            clothCnt[l]--;
        }

        Arrays.sort(lost);

        for (int l : lost) {
            if (clothCnt[l] != 0)
                continue;
            if (l != 1 && clothCnt[l - 1] == 2) { // 왼쪽이 남아있으면 무조건 왼쪽에게
                clothCnt[l - 1]--;
                clothCnt[l]++;
            } else if (l != n && clothCnt[l + 1] == 2) {
                clothCnt[l + 1]--;
                clothCnt[l]++;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (clothCnt[i] > 0)
                answer++;
        }
        return answer;
    }
}