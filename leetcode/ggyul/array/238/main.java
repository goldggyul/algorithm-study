class Solution {
    /*
    answer[i]: sum(nums[0..i-1])+sum(nums[i+1...n-1]) 이어야함
    n이 10^5이므로, 10^10은 불가능, 따라서 n^2 불가능
    */

    public int[] productExceptSelf1(int[] nums) {
        int[] prefixProduct = new int[nums.length];
        int[] suffixProduct = new int[nums.length];

        prefixProduct[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i];
        }

        suffixProduct[nums.length - 1] = nums[nums.length - 1];
        for (int i = nums.length - 2; i >= 0; i--) {
            suffixProduct[i] = suffixProduct[i + 1] * nums[i];
        }

        int[] answer = new int[nums.length];
        answer[0] = suffixProduct[1];
        answer[nums.length - 1] = prefixProduct[nums.length - 2];
        for (int i = 1; i < nums.length - 1; i++) {
            answer[i] = prefixProduct[i - 1] * suffixProduct[i + 1];
        }
        return answer;
    }

    public int[] productExceptSelf(int[] nums) {
        int producted = 1;
        int[] answer = new int[nums.length];
        for(int i=0;i<nums.length;i++){
            answer[i] = producted;
            producted*=nums[i];
        }
        producted =1;
        for(int i=nums.length-1;i>=0;i--){
            answer[i]*=producted;
            producted*=nums[i];
        }
        return answer;
    }
}