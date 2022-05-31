class Solution {
    /*
     * N = 10^3
     */
    public int calcDivisor(int num) {
        int result = 0;
        for (int i = 1; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                if (i * i == num) {
                    result++;
                } else {
                    result += 2;
                }
            }
        }
        return result;
    }

    public int solution(int left, int right) {
        int answer = 0;
        for (int i = left; i <= right; i++) {
            int result = calcDivisor(i);
            if (result % 2 == 0) {
                answer += i;
            } else {
                answer -= i;
            }
        }
        return answer;
    }
}