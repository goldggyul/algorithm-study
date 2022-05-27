import java.util.*;

class Solution {
    /*
     * 10분
     * N=10^5
     * O(N)
     */
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        Map<String, Integer> map = new HashMap<String, Integer>();
        for (String c : completion) {
            if (map.containsKey(c)) {
                map.put(c, map.get(c) + 1);
            } else {
                map.put(c, 1);
            }
        }
        for (String p : participant) {
            if (map.containsKey(p)) {
                if (map.get(p) == 0) {
                    return p;
                }
                map.put(p, map.get(p) - 1);
            } else {
                return p;
            }
        }
        return answer;
    }
}