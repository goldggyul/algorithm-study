// https://programmers.co.kr/learn/courses/30/lessons/86491
class Solution {
    public int solution(int[][] sizes) {
        // 긴 건 가로로, 짧은 건 세로로 맞춤
        int widthMax = 0;
        int heightMin = 0;
        for (int[] size : sizes) {
            widthMax = Math.max(Math.max(size[0], size[1]), widthMax);
            heightMin = Math.max(Math.min(size[0], size[1]), heightMin);
        }
        return widthMax * heightMin;
    }
}