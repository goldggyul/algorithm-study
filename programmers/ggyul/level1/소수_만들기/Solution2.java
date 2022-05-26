import java.util.*;

class Solution {
    boolean[] isPrime = new boolean[50_005];

    public void update() {
        Arrays.fill(isPrime, true);
        for (int i = 2; i < 50_005; i++) {
            if (!isPrime[i])
                continue;
            for (int j = i * 2; j < 50_005; j += i) {
                isPrime[j] = false;
            }
        }
    }

    public int solution(int[] nums) {
        int answer = 0;
        update();
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                for (int k = j + 1; k < nums.length; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (isPrime[sum])
                        answer++;
                }
            }
        }
        return answer;
    }
}