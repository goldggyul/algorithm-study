import java.util.*;

class Solution {
    public String solution(String new_id) {
        String answer = "";
        // 1. 대문자->소문자
        new_id = new_id.toLowerCase();
        // 2. ^ -> 뒤에오는 걸 제외하고
        new_id = new_id.replaceAll("[^a-z0-9-_.]", "");
        // 3. 2번 이상 연속되면 하나의 마침표
        new_id = new_id.replaceAll("[.]{2,}", ".");
        // 4. 처음이나 끝에 있다면 제거
        new_id = new_id.replaceAll("^[.]|[.]$", "");
        // 5. 빈 문자열이면 a
        if (new_id.length() == 0)
            new_id = "a";
        // 6. 16자 이상이면 15자까지만
        if (new_id.length() >= 16)
            new_id = new_id.substring(0, 15);
        // 🌟 잘랐는데 마지막이 .이면 또 제거
        new_id = new_id.replaceAll("^[.]|[.]$", "");
        // 7. 길이가 3이될 때까지 마지막 반복
        while (new_id.length() <= 2) {
            new_id = new_id + new_id.charAt(new_id.length() - 1);
        }
        answer = new_id;
        return answer;
    }
}