class Solution {
    // 방법 1. DP
    public int maxProduct1(int[] nums) {
        int[] maxProduct = new int[nums.length];
        int[] minProduct = new int[nums.length];
        maxProduct[0] = Math.max(0, nums[0]);
        minProduct[0] = Math.min(0, nums[0]);
        int ans = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int productToMax = maxProduct[i - 1] * nums[i];
            int productToMin = minProduct[i - 1] * nums[i];

            maxProduct[i] = Math.max(Math.max(productToMax, productToMin), nums[i]);
            minProduct[i] = Math.min(Math.min(productToMax, productToMin), nums[i]);

            ans = Math.max(ans, maxProduct[i]);
        }
        return ans;
    }

    // 방법 2. Kadane
    public int maxProduct2(int[] nums) {
        int maxProduct = Math.max(0, nums[0]);
        int minProduct = Math.min(0, nums[0]);
        int ans = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int productToMax = maxProduct * nums[i];
            int productToMin = minProduct * nums[i];

            maxProduct = Math.max(Math.max(productToMax, productToMin), nums[i]);
            minProduct = Math.min(Math.min(productToMax, productToMin), nums[i]);

            ans = Math.max(ans, maxProduct);
        }
        return ans;
    }

}