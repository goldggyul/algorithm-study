class Solution {

    public int findMin1(int[] nums) {
        int l = 0;
        int r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }

    public int findMin2(int[] nums) {
        int l = 0;
        int r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[l] && nums[mid] > nums[r]) { // 둘보다 클때 -> 작은 쪽으로
                if (nums[l] < nums[r]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else if (nums[mid] < nums[l] && nums[mid] < nums[r]) { // 둘보다 작을 때 -> 큰 쪽으로
                if (nums[l] > nums[r]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else { // 둘 가운데일 때 -> 작은 쪽으로
                if (nums[l] < nums[r]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
        }
        return nums[l];
    }
}