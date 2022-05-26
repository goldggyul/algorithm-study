class Solution {
    /*
     * 최대 수
     * 50C3 = 50*49*48/3*2*1
     */
    public boolean isPrime(int num) {
        for (int i = 2; i <= Math.sqrt(num); i++) { // 루트 N까지만 계산해도 됨
            if (num % i == 0)
                return false;
        }
        return true;
    }

    public int solution(int[] nums) {
        int answer = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                for (int k = j + 1; k < nums.length; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (isPrime(sum))
                        answer++;
                }
            }
        }
        return answer;
    }
}