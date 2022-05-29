import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        Set<Integer> kind = new HashSet<>();
        for (int n : nums) {
            kind.add(n);
        }
        answer = (kind.size() > nums.length / 2) ? nums.length / 2 : kind.size();
        return answer;
    }
}