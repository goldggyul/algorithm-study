class Solution {
    public String tenToThree(int num) {
        String str = "";
        while (num > 0) {
            int rest = num % 3;
            str = Integer.toString(rest) + str;
            num /= 3;
        }
        return str;
    }

    public int threeToTen(long num) {
        long result = 0;
        long multiply = 1;
        while (num > 0) {
            result += (num % 10) * multiply;
            num /= 10;
            multiply *= 3;
        }
        return (int) result;
    }

    public int solution(int n) {
        int answer = 0;
        String three = tenToThree(n);

        StringBuffer sb = new StringBuffer(three);
        String reversedThree = sb.reverse().toString();

        answer = threeToTen(Long.parseLong(reversedThree));
        return answer;
    }
}