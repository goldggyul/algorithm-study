class Solution {
    public long solution(int price, int money, int count) {
        long priceSum = 0;
        for (int i = 1; i <= count; i++) {
            for (int j = 0; j < i; j++) {
                priceSum += price;
            }
        }
        if (money >= priceSum)
            return 0;
        else
            return priceSum - money;
    }
}