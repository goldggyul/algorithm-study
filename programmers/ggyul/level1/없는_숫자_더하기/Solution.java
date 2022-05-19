// https://programmers.co.kr/learn/courses/30/lessons/86051
class Solution {
    public int solution(int[] numbers) {
        int answer = 0;
        boolean[] isIn = new boolean[10];
        for (int number : numbers) {
            isIn[number] = true;
        }
        for (int i = 0; i < isIn.length; i++) {
            if (!isIn[i])
                answer += i;
        }
        return answer;
    }

    // Others Solution
    // 없는 걸 더해야하니까... 있는 걸 빼면 됨!
    public int solution2(int[] numbers) {
        int answer = 45;
        for (int number : numbers) {
            answer -= number;
        }
        return answer;
    }
}