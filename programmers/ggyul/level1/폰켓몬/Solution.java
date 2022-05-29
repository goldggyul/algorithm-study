// https://programmers.co.kr/learn/courses/30/lessons/1845
class Solution {
    /*
     * 최대한 많은 종류, n/2
     * n=10_000
     * 총 몇종류가 있는가?
     * 
     * 5분
     */
    public int solution(int[] nums) {
        int answer = 0;
        boolean[] isIn = new boolean[200_001];
        for (int n : nums) {
            if (!isIn[n]) {
                answer++;
                isIn[n] = true;
            }
        }
        answer = (answer > nums.length / 2) ? nums.length / 2 : answer;
        return answer;
    }
}