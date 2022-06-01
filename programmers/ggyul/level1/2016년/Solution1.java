class Solution {
    /*
     * 윤년이므로 2월은 29일까지
     * 1월 1일은 금요일
     */
    public String solution(int a, int b) {
        int curMonth = 1; // 1월 기준이므로 1부터 비교
        int day = 0;
        while (curMonth < a) {
            switch (curMonth) {
                case 2:
                    day += 29;
                    break;
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    day += 31;
                    break;
                default:
                    day += 30;
            }
            curMonth++;
        }
        day += (b - 1); // 1일 기준이므로 1을 뺀다
        int differ = day % 7;
        switch (differ) {
            case 0:
                return "FRI";
            case 1:
                return "SAT";
            case 2:
                return "SUN";
            case 3:
                return "MON";
            case 4:
                return "TUE";
            case 5:
                return "WED";
            default:
                return "THU";
        }
    }
}