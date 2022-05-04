// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
    /*
    # 문제
    prices[i]: i번째 날의 주어진 제품의 가격
    한가지 재고를 사기 위한 single day를 골라서 이익 최대화, 다른 날에 팜
    가능한 최대 이익은?
    얻을 수 있는 이익 없을 땐 0
    ---
    # 해결
    즉 쌀 때 사서 비쌀 때 팔아야함
    n=10^5 -> 10^10 n^2 불가능
    */
    public int maxProfit(int[] prices) {
        int result = 0; // 현재 차이 최대값
        int m = prices[0]; // 현재 최소값. m 바뀔 때 result 한 번 체크
        for (int i = 1; i < prices.length; i++) {
            result = Math.max(result, prices[i] - m);
            m = Math.min(m, prices[i]);
        }
        return result;
    }
}