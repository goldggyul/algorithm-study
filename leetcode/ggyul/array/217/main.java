// https://leetcode.com/problems/contains-duplicate/
class Solution {
    /*
    중복되는 수가 하나라도 있으면 true, 아니면 false
    */

    // 방법1. 탐색만 빠르게 하면 되므로, HashSet 이용
    public boolean containsDuplicate1(int[] nums) {
        Set<Integer> input = new HashSet<Integer>();
        for(int num:nums){
            if(input.contains(num)){
                return true;
            }
            input.add(num);
        }
        return false;
    }

    // 방법2. 정렬해서 중복 원소 있는 지 확인
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        for(int i=1;i<nums.length;i++){
            if(nums[i-1]==nums[i])
                return true;
        }
        return false;
    }
}