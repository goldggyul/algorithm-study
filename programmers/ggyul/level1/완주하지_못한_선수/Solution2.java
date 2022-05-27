import java.util.*;

class Solution {
    /*
     * N=10^5
     */
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        Map<String, Integer> map = new HashMap<String, Integer>();
        for (String c : completion) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        for (String p : participant) {
            Integer result = map.getOrDefault(p, 0);
            if (result == 0)
                return p;
            map.put(p, result - 1);
        }
        return answer;
    }
}