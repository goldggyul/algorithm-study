package programmers.ggyul.level1.신고_결과_받기;

import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];

        // key가 몇번 신고당했는 지
        Map<String, Integer> reportCnt = new HashMap<String, Integer>();
        // key가 신고한 id들 모음
        Map<String, Set<String>> reportRecord = new HashMap<String, Set<String>>();

        // 0. 초기화
        for (String id : id_list) {
            reportCnt.put(id, 0);
            reportRecord.put(id, new HashSet<String>());
        }

        // 1. key가 신고한 id 기록
        for (String r : report) {
            String[] fromTo = r.split(" ");
            reportRecord.get(fromTo[0]).add(fromTo[1]);
        }

        // 2. 신고 기록 보면서 카운트
        for (String id : id_list) {
            for (String r : reportRecord.get(id)) {
                reportCnt.put(r, reportCnt.get(r) + 1);
            }
        }

        // 3.
        for (int i = 0; i < id_list.length; i++) {
            for (String reportId : reportRecord.get(id_list[i])) {
                if (reportCnt.get(reportId) >= k) {
                    answer[i]++;
                }
            }
        }

        return answer;
    }
}