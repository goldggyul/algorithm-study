// https://programmers.co.kr/learn/courses/30/lessons/12906
import java.util.*;

public class Solution {
    public int[] solution(int[] arr) {
        int[] answer = {};
        List<Integer> list = new ArrayList<Integer>();
        int prior = -1;
        for (int i = 0; i < arr.length; i++) {
            if (prior != arr[i])
                list.add(arr[i]);
            prior = arr[i];
        }
        answer = list.stream().mapToInt(i -> i).toArray();
        return answer;
    }
}