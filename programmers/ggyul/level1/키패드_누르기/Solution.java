// https://programmers.co.kr/learn/courses/30/lessons/67256
class Solution {
    
    // 숫자의 x좌표 리턴
    public int getX(int to) {
        if (to == 0) {
            return 3;
        }
        return (to - 1) / 3;
    }

    // 숫자의 y좌표 리턴
    public int getY(int to) {
        if (to == 0) {
            return 1;
        }
        return (to - 1) % 3;
    }

    // x,y로부터 숫자까지의 거리 리턴
    public int getDist(int fromX, int fromY, int to) {
        int toX = getX(to);
        int toY = getY(to);
        return Math.abs(fromX - toX) + Math.abs(fromY - toY);
    }

    public String solution(int[] numbers, String hand) {
        String answer = "";

        int lx = 3, ly = 0;
        int rx = 3, ry = 2;
        for (int i = 0; i < numbers.length; i++) {
            boolean isLeft = false;

            // 왼쪽손일때
            if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
                isLeft = true;
            } else if (numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0) { // 가운데 -> 거리 가까운 것
                int ld = getDist(lx, ly, numbers[i]);
                int rd = getDist(rx, ry, numbers[i]);
                if (ld == rd) {
                    if (hand.equals("left")) { // 거리 같을 땐 왼손잡이 vs. 오른손잡이 기준
                        isLeft = true;
                    }
                } else if (ld < rd) { // 왼손이 가까울 때
                    isLeft = true;
                }
            }

            if (isLeft) {
                answer += "L";
                lx = getX(numbers[i]);
                ly = getY(numbers[i]);
            } else {
                answer += "R";
                rx = getX(numbers[i]);
                ry = getY(numbers[i]);
            }
        }
        return answer;
    }
}