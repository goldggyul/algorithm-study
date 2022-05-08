// https://leetcode.com/problems/maximum-subarray/
class Solution {
    // 방법 1. d[i]에는 i를 포함하는 maxSum
    public int maxSubArray1(int[] nums) {
        int[] d=new int[nums.length];
        d[0]=nums[0];
        int ans = d[0];
        for(int i=1;i<nums.length;i++){
            d[i]=Math.max(nums[i], d[i-1]+nums[i]);
            ans=Math.max(ans, d[i]);
        }
        return ans;
    }

    // 방법2. Kadane Algorithm
    public int maxSubArray2(int[] nums) {
        int maxSum = Integer.MIN_VALUE;
        int sum=0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            maxSum = Math.max(maxSum, sum);
            if(sum<0){
                sum = 0;
            }
        }
        return maxSum;
    }
}