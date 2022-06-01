class Solution {
    /*
     * 윤년이므로 2월은 29일까지
     * 1월 1일은 금요일
     */
    int[] monthDay = new int[] { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    String[] dayString = new String[] { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };

    public String solution(int a, int b) {
        int day = 0;
        for (int i = 1; i < a; i++) { // 1월 기준이므로 1부터 비교 
            day += monthDay[i];
        }
        day += (b - 1); // 1일 기준이므로 1을 뺀다

        int differ = day % 7;
        return dayString[differ];
    }
}
