// https://programmers.co.kr/learn/courses/30/lessons/12910
import java.util.*;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        int[] answer = {};
        Set<Integer> divided = new TreeSet<>();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % divisor == 0) {
                divided.add(arr[i]);
            }
        }
        if (divided.size() == 0)
            answer = new int[] { -1 };
        else
            answer = divided.stream().mapToInt(i -> i).toArray();
        return answer;
    }
}