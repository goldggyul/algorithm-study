class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        for (int[] size : sizes) {
            // 긴 건 가로로, 짧은 건 세로로 맞춤
            if (size[0] < size[1]) {
                size[0] = size[0] ^ size[1];
                size[1] = size[0] ^ size[1];
                size[0] = size[0] ^ size[1];
            }
        }
        int widthMax = 0;
        int heightMax = 0;
        for (int[] size : sizes) {
            widthMax = Math.max(size[0], widthMax);
            heightMax = Math.max(size[1], heightMax);
        }
        return widthMax * heightMax;
    }
}